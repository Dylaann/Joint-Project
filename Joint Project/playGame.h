#pragma once
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>
#ifndef PLAYGAME
#define PLAYGAME




// classs for the menu screen 
class Game;



#include<SFML\Graphics.hpp>
#include"Button.h"
#include"Widget.h"
#include "GUI.h"
#include"Game.h"

class playGame  {


public:
		playGame(Game &game);
		~playGame();

		void render(sf::RenderWindow & window);
		void update();

private:

	GUI m_gui;
	Label *m_title;
	Button *m_mapSelection;
	Button *moveLeft;
	Button *m_rectB;
	Button *moveRight;
	Button *moveDowner;
	Button *moveDownest;
	Button *goBack;
	int m_currentSelect;
	//void setRectColor(sf::Color color);
	sf::RectangleShape m_rect;
	bool maptrue = false;

	sf::Sprite dayMapSprite;
	sf::Sprite nightMapSprite;
	Game *m_game;
	void goToMenu();
	void goToSpecs();
	void goToSpecsMap2();

};

#endif // !PLAYGAME