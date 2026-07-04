/*
	This file is part of ARTxT, a software for Augmented Reality on TeXT.
	Copyright (c) 2011 Hideaki Uchiyama

	You can use, copy, modify and re-distribute this software
	for non-profit purposes.
*/

#include "llah.h"

void LLAH::ClearPaper()
{
	m_table.Clear();
	m_paperlist.Clear();
}

void LLAH::DeletePaper()
{
	for(visible::iterator itvi=m_visible.begin();itvi!=m_visible.end();++itvi){
		for(ptlist::iterator itpt=(*itvi)->pts.begin();itpt!=(*itvi)->pts.end();++itpt){
			for(descriptors::iterator itde=(*itpt).desc.begin();itde!=(*itpt).desc.end();++itde){
				m_table.Delete(static_cast<unsigned>(*itde), (*itpt).id);
			}
		}
	}
}

void LLAH::SetHash(Paper* paper, const eblobs *blobs)
{
	for(eblobs::const_iterator itbl=blobs->begin();itbl!=blobs->end();++itbl){
		for(descriptors::iterator itde=(*itbl)->descs.begin();itde!=(*itbl)->descs.end();++itde){
			bool flag = m_table.Set(static_cast<unsigned>(*itde), (*itbl)->id);

			if(flag){
				paper->pts[(*itbl)->PtID()].desc.insert(static_cast<unsigned>(*itde));
			}
		}
	}
}


void LLAH::AddPaper(const MyImage &src)
{
	eblobs *blobs = m_bloblist.GetExtracted();
	unsigned paperid = m_paperlist.Add(src, blobs);
	Paper* paper = m_paperlist.FindPaper(paperid);

	SetHash(paper, blobs);
}


visible* LLAH::GetVisiblePaper()
{
	return &m_visible;
}

bool LLAH::FindPaper(const int min, const double repro)
{
	m_visible.clear();

	bool flag = false;
	
	nblobs *bloblist = m_bloblist.SortbyPaper(min);

	for(nblobs::iterator itbl=bloblist->begin();itbl!=bloblist->end();++itbl){
		unsigned paperid = (*(*itbl).second).first;

		Paper* paper = m_paperlist.FindPaper(paperid);
		
		if(paper != NULL){

			eblobs *blobs = &(*(*itbl).second).second;

			int num = static_cast<int>(blobs->size());

			MyMat impts(3,num), dbpts(3,num);

			int i = 0;
			for(eblobs::iterator itbl=blobs->begin();itbl!=blobs->end();++itbl){
				impts(0,i) = (*itbl)->x;
				impts(1,i) = (*itbl)->y;
				impts(2,i) = 1.0;

				unsigned ptid = (*itbl)->PtID();
				dbpts(0,i) = paper->pts[ptid].x;
				dbpts(1,i) = paper->pts[ptid].y;
				dbpts(2,i) = 1.0;
				
				++i;
			}

			paper->h.Homography(dbpts, impts, repro);
			impts.Mul(paper->h, dbpts);

			i=0;
			for(eblobs::iterator itbl=blobs->begin();itbl!=blobs->end();){
				double x = impts(0,i)/impts(2,i);
				double y = impts(1,i)/impts(2,i);

				double distance = (*itbl)->Distance(x, y);
				if(distance > repro){
					itbl = blobs->erase(itbl);
				}
				else{
					++itbl;
				}

				++i;
			}

			if(static_cast<int>(blobs->size()) > min){
				flag = true;
				m_visible.push_back(paper);
			}

		}
	}
	
	return flag;
}

double LLAH::ComputeAffine(const blob *target, const combi &nm, const combi &mk) const
{
	blob* p0 = target->nblobs[nm[mk[0]]];
	blob* p1 = target->nblobs[nm[mk[1]]];
	blob* p2 = target->nblobs[nm[mk[2]]];
	blob* p3 = target->nblobs[nm[mk[3]]];

	return p0->Triangle(p1,p2)/(p0->Triangle(p2,p3)+0.00000001);
}

unsigned LLAH::ComputeIndex(const blob *target, const combi &nm) const
{
	unsigned index=0;

	for(allcombi::const_iterator itmk=m_param.mk.begin();itmk!=m_param.mk.end();++itmk){
		index = index << m_param.stepbit;
		double val = ComputeAffine(target, nm, *itmk);
		index += m_param.Quantization(val);

		if(index > m_param.hashsize){
			index = index % m_param.hashsize;
		}
	}

	return index % m_param.hashsize;
}

void LLAH::ComputeDescriptors(blob *target) 
{
	for(allcombi::iterator itnm=m_param.nm.begin();itnm!=m_param.nm.end();++itnm){
		unsigned index = ComputeIndex(target, *itnm);
		target->descs.insert(index);
	}
}

void LLAH::Retrieve()
{
	eblobs *blobs = m_bloblist.GetExtracted();

	if(static_cast<int>(blobs->size()) > m_param.n){
		m_bloblist.SetNeighbor(m_param.n);

		for(eblobs::iterator itbl=(*blobs).begin();itbl!=(*blobs).end();++itbl){
			ComputeDescriptors(*itbl);
			m_table.ComputeID(*itbl);
		}
	}
}

void LLAH::CoordinateTransform(const double h, const double ratio)
{
	eblobs* blobs = m_bloblist.GetExtracted();

	for(eblobs::iterator itb=(*blobs).begin();itb!=(*blobs).end();++itb){

		(*itb)->rawx /= ratio;
		(*itb)->rawy /= ratio;

		(*itb)->x = (*itb)->rawx;
		(*itb)->y = h - (*itb)->rawy;
	}
}

void LLAH::SetPts()
{
	m_label.Labeling(m_binary);
	m_bloblist.SetBlobs(m_label);
}

void LLAH::Extract(const MyImage &src)
{
	m_gray.ColortoGray(src);
	m_blur.Smooth(m_gray);
	m_binary.Binarization(m_blur);
}

void LLAH::Init(const int iw, const int ih)
{
	m_gray.Init(iw,ih,1);
	m_blur.Init(iw,ih,1);
	m_binary.Init(iw,ih,1);
	m_label.Init(iw,ih);
	m_bloblist.Init(iw,ih,10);
}

void LLAH::DrawBinary(MyImage &dst) const
{
	MyImage tmp;
	tmp.Init(m_binary.w, m_binary.h, 3);

	tmp.GraytoColor(m_binary);
	dst.Resize(tmp);
}

void LLAH::DrawPts(MyImage &dst) const
{
	const eblobs *blobs = m_bloblist.GetExtracted();

	for(eblobs::const_iterator itbl=(*blobs).begin();itbl!=(*blobs).end();++itbl){
		dst.Circle(static_cast<int>((*itbl)->rawx), static_cast<int>((*itbl)->rawy), 3, -1, 255);
	}
}