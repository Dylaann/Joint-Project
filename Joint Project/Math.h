#pragma once
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <Thor/Vectors.hpp>

namespace Math
{
	double distance(sf::Vector2f v1, sf::Vector2f v2);
	sf::Vector2f truncate(sf::Vector2f v, float num);
	float dotProduct(sf::Vector2f a, sf::Vector2f b);
	float length(sf::Vector2f a);
	bool lineIntersectsCircle(sf::Vector2f ahead, sf::Vector2f halfAhead, sf::Sprite sprite);
};

