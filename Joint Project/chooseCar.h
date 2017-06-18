#pragma once
#include<SFML\Graphics.hpp>
#include"Game.h"
#include<iostream>
#include<fstream>
#include<cctype>
#include "GUI.h"
#ifndef CHOOSECAR
#define CHOOSECAR
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

class Game;
//this is the screen where the player chooses their cars texture
class ChooseCar {
public:
	ChooseCar(Game &game); //constructor
	void draw(sf::RenderWindow &window); // draw loop
	void update(); //update loop
	sf::Texture getCar(); //return the texture of the car
	void chooseCar(); //choose the car texture

private:
	Game *m_game; //game object
	GUI m_gui; //gui
	int m_selectedItem = 0;
	Button *m_cars[9];//widgets
	sf::Texture m_textures[9]; //the textures of the cars
	sf::Sprite m_spr; //sprite to draw them to the screen
	float m_rotation = 0;
	Label *m_label;
};
#endif