struct Pixel 
{
public:
	int XPosition;
	int YPosition;
	int RColorChannel;
	int GColorChannel;
	int BColorChannel;

	Pixel(int xPosition, int yPosition, 
		int rColorChannel, int gColorChannel, int bColorChannel);

	~Pixel();
};