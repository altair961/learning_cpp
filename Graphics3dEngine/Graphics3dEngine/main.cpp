#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
using namespace std;

struct vec3d
{
	float x, y, z;
};

struct triangle
{
	vec3d p[3];
	olc::Pixel color;
};

struct mesh
{
	vector<triangle> tris;
};

struct mat4x4 
{
	float m[4][4] = { 0 };
};

class Graphics3dEngine : public olc::PixelGameEngine
{
public:
	Graphics3dEngine()
	{
		sAppName = "Graphics3dEngine";
	}

private:
	mesh meshCube;
	mat4x4 matProj;
	vec3d vCamera;

	float fTheta;

	void MultiplyMatrixVector(vec3d& i, vec3d& o, mat4x4& m) // input 3D point, transformed 3D point, transformation or projection matrix 
	{
		o.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + m.m[3][0];
		o.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + m.m[3][1];
		o.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + m.m[3][2];
		float w = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + m.m[3][3]; // this element appeared in our tranformation matrix due to the fact that there is a gap between user's head and near plane of view frustum

		// Now we on 4D, in order to come back to 3D cartesian space we have to divide by w
		if(w != 0)
		{
			o.x /= w; o.y /= w; o.z /= w;
		}
	}

	olc::Pixel GetShadedColor(int red, int green, int blue, int alpha, float luminance)
	{
		float shadeFactor = 1 - luminance;
		int shade = shadeFactor * 255;

		red = red - shade;
		green = green - shade;
		blue = blue - shade;
		alpha = alpha - shade;

		// the lowest allowed value of color is 0 so we replace negative values with 0
		red = red < 0 ? 0 : red;
		green = green < 0 ? 0 : green;
		blue = blue < 0 ? 0 : blue;
		alpha = alpha < 0 ? 0 : alpha;

		olc::Pixel result = olc::Pixel(red, green, blue, alpha);

		return result;
	}

public:
	bool OnUserCreate() override
	{
		meshCube.tris = {

			// SOUTH
			{ 0.0f, 0.0f, 0.0f,    0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 0.0f },
			{ 0.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 0.0f, 0.0f },

			// EAST                                                      
			{ 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f },
			{ 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f, 1.0f },

			// NORTH                                                     
			{ 1.0f, 0.0f, 1.0f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f, 1.0f },
			{ 1.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 0.0f, 1.0f },

			// WEST                                                      
			{ 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 1.0f, 0.0f },
			{ 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 0.0f,    0.0f, 0.0f, 0.0f },

			// TOP                                                       
			{ 0.0f, 1.0f, 0.0f,    0.0f, 1.0f, 1.0f,    1.0f, 1.0f, 1.0f },
			{ 0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f, 0.0f },

			// BOTTOM                                                    
			{ 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f },
			{ 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f,    1.0f, 0.0f, 0.0f },

		};

		// we define our transformation or "projection" matrix once in OnUserCreate,
		// because the screen dimention and field of view are not going to change in this app
		// Transformation matrix
		float fNear = 0.1f;
		float fFar = 1000.0f;
		float fFov = 90.0f; // fov stands for field of view in degrees
		float fAspectRatio = (float)ScreenHeight() / (float)ScreenWidth();
		float fFovRad = 1.0f / tanf(fFov * 0.5f / 100.0f * 3.14159f); // tangent calculation of theta/2 angle i.e. our scaling factor

		//       [y][x]
		matProj.m[0][0] = fAspectRatio * fFovRad;
		matProj.m[1][1] = fFovRad;
		matProj.m[2][2] = fFar / (fFar - fNear);
		matProj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
		matProj.m[2][3] = 1.0f;
		matProj.m[3][3] = 0.0f;

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		auto pixel = olc::Pixel(253, 246, 227, 255);
		Clear(pixel);

		mat4x4 matRotZ, matRotX;
		fTheta += 1.0f * fElapsedTime;

		// Rotation Z
		matRotZ.m[0][0] = cosf(fTheta);
		matRotZ.m[0][1] = sinf(fTheta);
		matRotZ.m[1][0] = -sinf(fTheta);
		matRotZ.m[1][1] = cosf(fTheta);
		matRotZ.m[2][2] = 1;
		matRotZ.m[3][3] = 1;

		// Rotation X
		matRotX.m[0][0] = 1;
		matRotX.m[1][1] = cosf(fTheta * 0.5f);
		matRotX.m[1][2] = sinf(fTheta * 0.5f);
		matRotX.m[2][1] = -sinf(fTheta * 0.5f);
		matRotX.m[2][2] = cosf(fTheta * 0.5f);
		matRotX.m[3][3] = 1;

		// Draw Triangles
		for (auto tri : meshCube.tris)
		{
			triangle triProjected, triTranslated, triRotatedZ, triRotatedZX; // we have to translate the triangle into the view out from our face (along z-axis into the screen)
			
			// Rotate in Z-Axis
			MultiplyMatrixVector(tri.p[0], triRotatedZ.p[0], matRotZ);
			MultiplyMatrixVector(tri.p[1], triRotatedZ.p[1], matRotZ);
			MultiplyMatrixVector(tri.p[2], triRotatedZ.p[2], matRotZ);

			// Rotate in X-Axis
			MultiplyMatrixVector(triRotatedZ.p[0], triRotatedZX.p[0], matRotX);
			MultiplyMatrixVector(triRotatedZ.p[1], triRotatedZX.p[1], matRotX);
			MultiplyMatrixVector(triRotatedZ.p[2], triRotatedZX.p[2], matRotX);

			// Offset into the screen
			triTranslated = triRotatedZX;
			triTranslated.p[0].z = triRotatedZX.p[0].z + 3.0f;
			triTranslated.p[1].z = triRotatedZX.p[1].z + 3.0f;
			triTranslated.p[2].z = triRotatedZX.p[2].z + 3.0f;

			vec3d normal, line1, line2; // Type vec3d is used both for representing vectors and poinits in 3D space
			line1.x = triTranslated.p[1].x - triTranslated.p[0].x; // line1 is a vector A. We calculate vector based on point's elements subtraction. Ex.: Given point (1,2) and point (3,5). Subtracting x and y elements correspondingly gives us a vector: <3-1, 5-2> = <2, 3>
			line1.y = triTranslated.p[1].y - triTranslated.p[0].y; 
			line1.z = triTranslated.p[1].z - triTranslated.p[0].z;

			line2.x = triTranslated.p[2].x - triTranslated.p[0].x; // line2 is a vector B
			line2.y = triTranslated.p[2].y - triTranslated.p[0].y;
			line2.z = triTranslated.p[2].z - triTranslated.p[0].z;

			normal.x = line1.y * line2.z - line1.z * line2.y; // normal is a vector that we calculated based on vector A and vector B assuming that normal is perpendicular to A and to B simultaniously
			normal.y = line1.z * line2.x - line1.x * line2.z;
			normal.z = line1.x * line2.y - line1.y * line2.x;

			// normalizing or scaling the normal vector
			float normalLength = sqrtf(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z); // we calculate normal vector length
			normal.x /= normalLength; normal.y /= normalLength; normal.z /= normalLength; // dividing x, y and z by length gives us a unit-vector
			// normalizing the normal is not optional. 
			
			// Let's say we have some vector <3,5,-9> for normal, we move the image of the vector so that its origin is on origin of the space (0,0,0) now we see, that arrow beginning in (0,0,0) point points to the direction opposite of growing Z
			//if (normal.z < 0) // if normal points to us we see the triangle, otherwise we should not see the triangle

			// Dot product says how similar are two vectors. 
			// When we calculate dot product we get score == 1 for same vectors, 0 if vectors are not similar at all, meaning they are perpendicular, and score == -1 for vectors on same line but pointing to opposite directions.
			// Dot product D of A and B vectors is : D = Ax * Bx + Ay * By + Az * Bz
			// In order to get scores like "1" instead of "576786" or so on we first normalized the vectors before calculating their dot product.

			// We can take any point of traingle since all three points are on the same plane. Let's take p[0] for example.
			vec3d vecPointingFromCamToTri; 
			vecPointingFromCamToTri.x = triTranslated.p[0].x - vCamera.x; // from some point of triangle we subtract point where camera sits to get vector pointing from camera to triangle
			vecPointingFromCamToTri.y = triTranslated.p[0].y - vCamera.y;
			vecPointingFromCamToTri.z = triTranslated.p[0].z - vCamera.z;

			float dotProductOfVecPointingFromCamToTriAndNormal =
				normal.x * vecPointingFromCamToTri.x +
				normal.y * vecPointingFromCamToTri.y +
				normal.z * vecPointingFromCamToTri.z;

			// we draw only those triangles that have normal pointing towards camera meaning that normal vector and vecPointingFromCamToTri point towards each other (basically they point opposite directions and they do not point to the same direction) meaning they have dot product equals less than 0 
			if(dotProductOfVecPointingFromCamToTriAndNormal < 0.0f) 
			{
				// Illumination. We shade only the triangles, that are going to be drawn to save resources. Because the more calculations we add, the more expensive it is to draw a triangle.
				vec3d lightDirection = { 0.0f, 0.0f, -1.0f }; // this is not a point from which the light is comming out. It is a vector, that shows direction of the light. It points to the player's head.
				// Triangle is more lit the more its normal is inline with the line of light direction. Basically light is pointing at us, and normal of some triangle is pointing to us, so these two vectors are same, then the triangle should be lit a lot

				// normalizing the light direction. So now we can change light direction vector without consequences
				float lightDirectionLength = sqrtf(lightDirection.x * lightDirection.x + lightDirection.y * lightDirection.y + lightDirection.z * lightDirection.z); // we calculate lightDirection vector length
				lightDirection.x /= lightDirectionLength; lightDirection.y /= lightDirectionLength; lightDirection.z /= lightDirectionLength; // dividing x, y and z by length gives us a unit-vector

				float dotProductOfLightDirectionAndNormal =
					normal.x * lightDirection.x +
					normal.y * lightDirection.y +
					normal.z * lightDirection.z;

				olc::Pixel triangleShadedColor = GetShadedColor(62, 162, 151, 255, dotProductOfLightDirectionAndNormal);
				triTranslated.color = triangleShadedColor;

				// Project triangles from 3D --> 2D
				MultiplyMatrixVector(triTranslated.p[0], triProjected.p[0], matProj);
				MultiplyMatrixVector(triTranslated.p[1], triProjected.p[1], matProj);
				MultiplyMatrixVector(triTranslated.p[2], triProjected.p[2], matProj);
				triProjected.color = triTranslated.color;
				
				// Scale into view. We Used DrawTriangle to draw each triangle of the mesh. But it appears as one pixel because transformation gives us points between - 1 and +1
				triProjected.p[0].x += 1.0f; triProjected.p[0].y += 1.0f; // shift the x and y coordinate to be between 0 and 2
				triProjected.p[1].x += 1.0f; triProjected.p[1].y += 1.0f;
				triProjected.p[2].x += 1.0f; triProjected.p[2].y += 1.0f;

				// Divide x coordinate by 2 and scale it to the appropriate size for that axis. Do the same for y.
				triProjected.p[0].x *= 0.5f * (float)ScreenWidth();
				triProjected.p[0].y *= 0.5f * (float)ScreenHeight();
				triProjected.p[1].x *= 0.5f * (float)ScreenWidth();
				triProjected.p[1].y *= 0.5f * (float)ScreenHeight();
				triProjected.p[2].x *= 0.5f * (float)ScreenWidth();
				triProjected.p[2].y *= 0.5f * (float)ScreenHeight();

				//auto triangleColor = olc::Pixel(101, 123, 131, 255);

				olc::PixelGameEngine::FillTriangle(triProjected.p[0].x, triProjected.p[0].y,
					triProjected.p[1].x, triProjected.p[1].y,
					triProjected.p[2].x, triProjected.p[2].y, triProjected.color);

				//we leave this invocation for debugging purpouses. It is usefull to see all wires
				//olc::PixelGameEngine::DrawTriangle(triProjected.p[0].x, triProjected.p[0].y,
				//	triProjected.p[1].x, triProjected.p[1].y,
				//	triProjected.p[2].x, triProjected.p[2].y, lineColor);
			}
		}

		return true;
	}
};

int main()
{
	Graphics3dEngine graphics3dEngine;
	if (graphics3dEngine.Construct(800, 600, 1, 1))
		graphics3dEngine.Start();

	return 0;
}