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

class Graphics3dEngine : public olc::PixelGameEngine
{
public:
	Graphics3dEngine()
	{
		sAppName = "Graphics3dEngine";
	}

public:
	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		auto pixel = olc::Pixel(200, 200, 200, 200);
		Clear(pixel);

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