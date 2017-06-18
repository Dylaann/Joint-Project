#pragma once
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

#ifndef DIFFICULTYSCREEN
#define DIFFICULTYSCREEN

#include "GUI.h"
#include "Game.h"

class Game;

class DifficultyScreen {

public:
	DifficultyScreen(Game &game);
	void render(sf::RenderWindow & window);
	void update();
	void goToOptions();
	void setEasy();
	void setMedium();
	void setHard();
private:
	Game *m_game;
	GUI m_gui;
	static const int MAX_ITEMS = 4;

	Widget* m_widgets[MAX_ITEMS];
	int m_selectedItem;



};
#endif // !DIFFICULTYSCREEN