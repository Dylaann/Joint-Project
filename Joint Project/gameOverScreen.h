#pragma once
#ifndef GAMEOVERSCREEN
#define GAMEOVERSCREEN
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

#include "GUI.h"
#include "Game.h"

class Game;
//this is the screen that appears after the race
class GameOverScreen {
public:
	GameOverScreen(Game &game); //constructor
	void draw(sf::RenderWindow &window); //draw loop
	void update(); //update loop
	void goToGame(); //go to the menu

private:

	int m_selectedItem = 0;
	//widgets
	Label *m_label;
	Label *m_moneyEarned;
	Label *m_time;
	Label *m_placement;
	Button *m_button;
	static const int MAX_ITEMS = 1;
	Widget* m_widgets[MAX_ITEMS];
	Game *m_game;

	GUI m_gui; //gui
};
#endif