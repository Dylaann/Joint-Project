#pragma once
#include<SFML\Graphics.hpp>
#include"Game.h"
#include<iostream>
#include<fstream>
#include<cctype>
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

#ifndef BACKGROUND
#define BACKGROUND

//this class will represent the world / race track of the game
class Background {

public:
	Background(Game &m_game); //constructor
	void draw(sf::RenderWindow &window); //draw function
	void activateTheShader(); //activate blur shader
	
private:
	

	std::ifstream openFile; //for file reading

	std::string tileLocation; //texture name
	int visible; 
	
	sf::Texture m_tileTexture; //texture
	sf::Sprite spr; //sprite for tiles
	bool isOnTrack; //bool to indicate on track
	bool hitWall; //bool to indicate if wall is hit
	sf::Vector2i map[2000][2000]; //the map size
	sf::Vector2i loadCounter; //the amount of tiles

	Game *m_game; //pointer to game class

	sf::Shader m_shader;  //shaders	
	static bool activateShader; //turn on the blur shader
};
#endif