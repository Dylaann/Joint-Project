#pragma once
#ifndef TURBOSCREEN
#define TURBOSCREEN
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>
#include "GUI.h"
#include "Game.h"

class Game;

//screen where turbo is upgraded 
class TurboScreen {
public:
	TurboScreen(Game &game); //constructor
	void draw(sf::RenderWindow &window); //draw loop
	void update(); //update loop
	void goToGarage(); //go to the garage screen

	void currentUpgrade(); //equip the current upgrade
	bool m_smallEquipped; //small item equiped
	bool m_mediumEquipped;// medium item equiped
	bool m_largeEquipped; // large item equiped
private:
	sf::Sprite m_sprite; //sprite for the texture

	//widgets
	Label *m_label; 
	Label *m_playerMoney;
	static const int MAX_ITEMS = 4;
	Widget* m_widgets[MAX_ITEMS];
	int m_selectedItem = 0;
	GUI m_gui; //gui object
	Game *m_game; 
	void smallBuy();
	void mediumBuy();
	void largeBuy();
	bool m_smallBought;
	bool m_mediumBought;
	bool m_largeBought;
	const int SMALL_PRICE = 500;
	const int MEDIUM_PRICE = 2500;
	const int LARGE_PRICE = 5000; //prices

};
#endif