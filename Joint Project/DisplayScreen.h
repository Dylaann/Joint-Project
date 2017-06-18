#pragma once
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

#ifndef DISPLAYSCREEN
#define DISPLAYSCREEN

#include "Game.h"

class Game;

class DisplayScreen
{
public:
	DisplayScreen(Game &game);
	~DisplayScreen();
	void update();
	void render(sf::RenderWindow & window);

private:
	Game *m_game;
	GUI m_gui;
	Label *m_title;

	CheckBox *m_animeOn;

	Button *m_backButton;

	float m_speed;
	int m_currentSelect;
	void setStateBack();
	void animationOn();
};

#endif