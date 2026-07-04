/*
	This file is part of ARTxT, a software for Augmented Reality on TeXT.
	Copyright (c) 2011 Hideaki Uchiyama

	You can use, copy, modify and re-distribute this software
	for non-profit purposes.
*/

#include "hashtable.h"

bool HashTable::Delete(const unsigned index, const unsigned ptid)
{
	hashtable::iterator itin = m_table.find(index);

	if(itin != m_table.end()){
		hashlist::iterator itpt = (*itin).second.find(ptid);

		if(itpt != (*itin).second.end()){
			(*itin).second.erase(itpt);
			return true;
		}
	}

	return false;
}


bool HashTable::Set(const unsigned index, const unsigned ptid)
{
	hashtable::iterator itin = m_table.find(index);

	if(itin == m_table.end()){
		hashlist tmp;
		tmp.insert(ptid);
		m_table.insert(std::pair<unsigned, hashlist>(index, tmp));
	}
	else{
		hashlist::iterator itpt = (*itin).second.find(ptid);
		if(itpt == (*itin).second.end()){
			(*itin).second.insert(ptid);
		}
		else{
			return false;
		}	
	}

	return true;
}


void HashTable::ComputeID(blob *target) const
{
	typedef std::map<unsigned, int> evaluation;
	evaluation result;

	for(descriptors::const_iterator itta=target->descs.begin();itta!=target->descs.end();++itta){

		hashtable::const_iterator itha = m_table.find(*itta);

		if(itha != m_table.end()){

			for(hashlist::const_iterator itli=(*itha).second.begin();itli!=(*itha).second.end();++itli){
				
				evaluation::iterator itpt = result.find(*itli);

				if(itpt == result.end()){
					result.insert(std::pair<unsigned, int>(*itli, 1));
				}
				else{
					(*itpt).second++;
				}
			}
		}
	}

	if(static_cast<int>(result.size()) != 0){
		target->id = (*result.begin()).first;
		int count = (*result.begin()).second;

		for(evaluation::iterator itre=result.begin();itre!=result.end();++itre){
			if(count < (*itre).second){
				count = (*itre).second;
				target->id = (*itre).first;
			}
		}
	}
	else{
		target->id = NOID;
	}

}

void HashTable::Clear()
{
	m_table.clear();
}