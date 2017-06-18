#pragma once
#ifndef LISCENCE
#define LISCENCE
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

#include"Game.h"


class Game;

//class for Licence sceen
class Liscence
{
public:
	Liscence(Game &game);
	~Liscence();
	void update();
	void render(sf::RenderWindow & window);
	void load();

private:
	Game *m_game;
	sf::Time m_timer;

	sfe::Movie m_animation;
	bool m_play = true;

};

#endif