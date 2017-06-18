#pragma once
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

#ifndef SAVESCREEN
#define SAVESCREEN

class Game;

#include <SFML\Graphics.hpp>
#include <math.h>
#include "Button.h"
#include "GUI.h"
#include "Game.h"
#include <fstream>


class SaveScreen
{
public:
	SaveScreen(Game &game, Player &player);
	~SaveScreen();
	void render(sf::RenderWindow & window);
	void update();

private: 
	std::string fileName;
	std::ifstream fileInput;
	std::string fileLine;

	GUI m_gui;
	Button *m_profileOne;
	Button *m_profileTwo;
	Button *m_profileThree;
	Button *m_profileFour;
	Button *m_profileFive;
	Button *m_profileSix;
	Button *m_profileSeven;
	Button *m_profileEight;
	Button *m_profileNine;
	Button *m_profileTen;
	Button *m_Back;
	
	Label *m_currentName;
	int m_currentSelect;
	Game *m_game;
	Player *m_player;
	void goToMenu();
	void goToChangeProfile();
	void getProfileName();
	void saveFirstProfile();
	void saveSecondProfile();
	void saveThirdProfile();
	void saveFourthProfile();
	void saveFifthProfile();
	void saveSixthProfile();
	void saveSeventhProfile();
	void saveEighthProfile();
	void saveNinethProfile();
	void saveTenthProfile();
	std::string m_playerNames[10];
};

#endif