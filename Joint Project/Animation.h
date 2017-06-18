#pragma once
#include<SFML\Graphics.hpp>
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

class Animation {

public:
	Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);
	void update(int row, float dt);

	sf::IntRect uvRect;
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;

};