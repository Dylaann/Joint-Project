#pragma once
#include<SFML\Graphics.hpp>
#include"Game.h"
#include<iostream>
#include<fstream>
#include<cctype>

#ifndef NIGHTMODE
#define NIGHTMODE
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>
/// class to use the night vision shader
/// file: nightvision.frag
///<summary>
class NightMode {

public:
	NightMode(Game &m_game); //constructor
	void draw(sf::RenderWindow &window); //draw function
	void activateTheShader(bool activateshader1); //activate blur shader

private:

	sf::Clock elapsedTime;
	std::ifstream openFile; //for file reading

	std::string tileLocation; //texture name
	int visible;

	sf::Texture m_tileTexture; //texture
	sf::Sprite spr; //sprite for tiles
	bool isOnTrack; //bool to indicate on track
	bool hitWall; //bool to indicate if wall is hit
	sf::Vector2i map[2000][2000]; //the map size
	sf::Vector2i loadCounter; //the amount of tiles
	sf::Texture m_blankTexture;
	sf::Sprite m_shaderSprite;
	Game *m_game; //pointer to game class

	sf::Shader m_shader;

	bool activateShader; //turn on the blur shader

};
#endif