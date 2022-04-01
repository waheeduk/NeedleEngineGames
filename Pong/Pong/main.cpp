//The needle game engine is built on top of the SDL2 framework. More information about SDL can be found at
//https://www.libsdl.org. This software is built by Mohammed Ahmed (@waheeduk). More information about the
//needle game engine can be found at https://www.github.com/waheeduk/2D_Hitscan. This software is provided under the 
//MIT license.

#include <SDL.h>
#include "game.hpp"

int main(int argc, char* argv[])
{
	Game game(800, 600);
	bool success = game.Initialise();
	if (success)
	{
		game.RunLoop();
	}
	game.Shutdown();
	return 0;
}