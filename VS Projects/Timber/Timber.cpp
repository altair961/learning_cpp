#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{ 
	// Create a video mode object
	VideoMode vm(800, 600);

	// Create and open a window for the game
	RenderWindow window(vm, "Timber!!!", Style::Fullscreen);
	
	return 0;
}