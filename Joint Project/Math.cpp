#include "Math.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

namespace Math
{
	double distance(sf::Vector2f v1, sf::Vector2f v2)
	{
		return std::sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
	}

	sf::Vector2f truncate(sf::Vector2f v, float num)
	{
		float i;
		i = num / thor::length(v);
		i = i < 1.0 ? i : 1.0;
		v *= i;
		return v;
	}

	float dotProduct(sf::Vector2f a, sf::Vector2f b)
	{
		return (a.x * b.x) + (a.y * b.y);
	}

	float length(sf::Vector2f a)
	{
		return std::sqrt((a.x * a.x) + (a.y * a.y));
	}



	bool lineIntersectsCircle(sf::Vector2f ahead, sf::Vector2f halfAhead, sf::Sprite sprite)
	{
		return distance(sprite.getPosition(), ahead) < sprite.getGlobalBounds().width ||
			distance(sprite.getPosition(), halfAhead) < sprite.getGlobalBounds().width;
		
	}
}