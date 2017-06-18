#pragma once
#ifndef ACCELERATIONSCREEN
#define ACCELERATIONSCREEN

/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

#include "GUI.h"
#include "Game.h"

class Game;

//screen where acceleration of the players car can be upgraded
class AccelerationScreen {
public:
	AccelerationScreen(Game &game); //constructor
	void draw(sf::RenderWindow &window); //draw loop
	void update(); //update loop 
	void goToGarage(); //go to garage gamestate
	void currentUpgrade();	// To tell player what acceleration they have selected

private:
	Game *m_game;//game object
	sf::Sprite m_sprite;	//sprite to display on screen
	Label *m_label; //label heading
	Label *m_playerMoney;  //the players balance
	static const int MAX_ITEMS = 4; //number of ui elements
	Widget* m_widgets[MAX_ITEMS];	// Holder for all widgets
	int m_selectedItem = 0;	// int to tell Widget gui is currently selected
	GUI m_gui;			// Holds all the gui objects and update/renders them at once
	void smallBuy(); //buy the small upgrade
	void mediumBuy(); //medium upgrade
	void largeBuy(); //large upgrade
	bool m_smallBought;		// Bool so we know if the small acceleration was bought
	bool m_mediumBought;	// Bool to tell if the medium acceleration was bought
	bool m_largeBought;		// Bool to tell if the large acceleration was bought
	bool m_smallEquipped;	// Bool to know if the small acceleration is equipped
	bool m_mediumEquipped;	// Bool to know if the medium acceleration is equipped
	bool m_largeEquipped;	// Bool to know if the large acceleration is equipped

	// Prices for each of the upgrades
	const int SMALL_PRICE = 500;
	const int MEDIUM_PRICE = 2500;
	const int LARGE_PRICE = 5000;
};
#endif