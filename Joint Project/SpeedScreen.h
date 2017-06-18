#pragma once
#ifndef SPEEDSCREEN
#define SPEEDSCREEN
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

#include "GUI.h"
#include "Game.h"

class Game;

//screen where speed can be upgraded
class SpeedScreen {
public:
	SpeedScreen(Game &game); //constructor
	void draw(sf::RenderWindow &window); //draw loop
	void update(); //update loop
	void goToGarage(); //go to the garage menu

	void currentUpgrade(); //equip the current upgrade
private:
	sf::Sprite m_sprite; //sprite for the texture
	//widgets
	Label *m_label;
	Label *m_playerMoney;
	static const int MAX_ITEMS = 4;
	Widget* m_widgets[MAX_ITEMS];
	int m_selectedItem = 0;
	GUI m_gui; //gui
	Game *m_game; //game pointer
	void smallBuy();
	void mediumBuy();
	void largeBuy(); 
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