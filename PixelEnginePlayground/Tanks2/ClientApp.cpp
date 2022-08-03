#include "game.h"
#include <string>
#include <iostream>
#include <thread>
#include "pixelEngine.h"

// The function we want to execute on the new thread.
//void task1(std::string msg)
//{
//	while (true)
//	{
//		std::cout << "task1 says: " << msg << std::endl;
//	}
//
//}

int main()
{
	Game game;
	game.Launch();

	//PixelEngine pixelEngine;
	//if (game.Construct(256, 240, 4, 4))
	//	game.Start();

	// Constructs the new thread and runs it. Does not block execution.
	/*std::thread t1(task1, "Hello");

	while (true)
	{
		std::cout << "main thread" << std::endl;
	}*/

	// Do other things...

	// Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
	//t1.join();

	return 0;
}
