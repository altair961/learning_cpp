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
		float fFovRad = 1.0f / tanf(fFov * 0.5f / 100.0f * 3.14159f);

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		auto pixel = olc::Pixel(200, 200, 200, 200);
		Clear(pixel);

		// Draw Triangles
		for (auto tri : meshCube.tris)
		{

		}

		return true;
	}
};

int main()
{
	Graphics3dEngine graphics3dEngine;
	if (graphics3dEngine.Construct(256, 240, 4, 4))
		graphics3dEngine.Start();

	return 0;
}