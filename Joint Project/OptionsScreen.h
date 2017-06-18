#pragma once
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>
#ifndef OPTIONSSCREEN
#define OPTIONSSCREEN

#include "GUI.h"
#include "Game.h"

class Game;


class OptionsScreen
{
public:
	OptionsScreen(Game &game);
	~OptionsScreen();
	void render(sf::RenderWindow & window);
	void update();

private:
	Game *m_game;
	GUI m_gui;
	Label *m_title;

	Button *m_difficultyButton;
	Button *m_soundButton;
	Button *m_displayButton;
	Button *m_backButton;

	int m_currentSelect;
	void setStateDifficulty();
	void setStateSound();
	void setStateDisplay();
	void setStateBack();
};

#endif // !OPTIONSSCREEN