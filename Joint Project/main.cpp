#ifdef _DEBUG
#pragma comment(lib,"sfml-graphics-d.lib")
#pragma comment(lib,"sfml-audio-d.lib")
#pragma comment(lib,"sfml-system-d.lib")
#pragma comment(lib,"sfml-window-d.lib")
#pragma comment(lib,"sfml-network-d.lib")
#pragma comment(lib,"sfeMovie-d.lib") 
#pragma comment(lib,"libyaml-cppmdd") 
#pragma comment(lib, "thor-d.lib")
#else
#pragma comment(lib,"sfml-graphics.lib")
#pragma comment(lib,"sfml-audio.lib")
#pragma comment(lib,"sfml-system.lib")
#pragma comment(lib,"sfml-window.lib")
#pragma comment(lib,"sfml-network.lib")
#pragma comment(lib,"sfeMovie.lib") 
#pragma comment(lib,"libyaml-cppmd") 
#pragma comment(lib, "thor-d.lib")
#endif

#include "Game.h"

/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>


int main(int argc, char* args[])
{
	Game game;

	game.init();
	game.run();

	return 0;
}