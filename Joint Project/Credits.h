#pragma once
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>
#ifndef CREDITS
#define CREDITS

#include "Game.h"

class Game;

//credits class
class Credits
{
public:
	Credits(Game &game, LevelData &level);
	~Credits();
	void update();
	void render(sf::RenderWindow & window);
	void load();
private:
	Game *m_game;
	LevelData *m_currentLevel;
	sfe::Movie m_credits;
	bool m_play = true;
};

#endif