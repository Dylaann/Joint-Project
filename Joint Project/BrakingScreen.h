#pragma once
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>
#ifndef BRAKINGSCREEN
#define BRAKINGSCREEN

#include "GUI.h"
#include "Game.h"

class Game;

//screen where the brake upgrades are purchased
class BrakingScreen {
public:
	BrakingScreen(Game &game); //constructor
	void draw(sf::RenderWindow &window); //draw loop
	void update(); //update loop
	void goToGarage(); //go to the garage gamestate

private:
	sf::Sprite m_sprite; //car part image
	Label *m_label; //header/title
	Label *m_playerMoney; //players balance
	static const int MAX_ITEMS = 4; //num of widgets
	int m_selectedItem = 0;
	Widget* m_widgets[MAX_ITEMS]; //widgets
	GUI m_gui; //gui
	Game *m_game;
	void smallBuy(); //small upgrade
	void mediumBuy(); //medium 
	void largeBuy(); //large
	bool m_smallBought;
	bool m_mediumBought;
	bool m_largeBought;
	bool m_smallEquipped;
	bool m_mediumEquipped;
	bool m_largeEquipped;

	const int SMALL_PRICE = 500;
	const int MEDIUM_PRICE = 2500;
	const int LARGE_PRICE = 5000; //prices
};
#endif