#pragma once
#ifndef SPECS
#define SPECS
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

#include<SFML\Graphics.hpp>
#include"Button.h"
#include "Widget.h"
#include "GUI.h"
#include "Game.h"
#include "levels.h"

class Game;
class Levels;

class specs {

public :

	specs(Game &game, Levels &level);
	~specs();

	void render(sf::RenderWindow & window);
	void update();


private:

	GUI m_gui;
	Label  *m_title;
	Button *m_Enemies;
	Button *m_Race;
	Slider *m_EnemiesNo;
	Button *m_Time;
	Button *m_laps;
	Button *m_Back;
	RadioButton *m_3;
	RadioButton *m_5;
	RadioButton *m_7;


	Game *m_game;
	Levels *m_currentLevel;
	void goToMapSelect();
	void goToMapRacing();
	void goToLapSelect3();
	void goToLapSelect5();
	void goToLapSelect7();
	int m_currentSelect;

	float m_EnemiesNum;
};
#endif