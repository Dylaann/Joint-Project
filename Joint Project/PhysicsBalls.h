#pragma once
#ifndef PHISICSBALLS
#define PHYSICSBALLS
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

#include "Game.h"

class Game;


// Class to create physics balls
class PhysicsBalls
{
public:
	PhysicsBalls(Game &game);
	~PhysicsBalls();

	void update();
	void render(sf::RenderWindow &window);
	void collision();
	std::vector<sf::Sprite> m_ballSprite;

private:
	Game *m_game;
	sf::Vector2f m_velocity;
	sf::Vector2f m_Position;

	bool m_collision;

};

#endif