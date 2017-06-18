#pragma once
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

#ifndef CHANGEPROFILE
#define CHANGEPROFILE

class Game;
class Player;

#include<SFML\Graphics.hpp>
#include<math.h>
#include"Button.h"
#include "GUI.h"
#include"Game.h"
#include <fstream>

class changeProfile {

public:
	changeProfile(Game &game, Player &player);
	~changeProfile();
	void update();
	void render(sf::RenderWindow &  window);

private:

	std::string filename;
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
	Button *m_Save;
	Button *m_New;

	Label *m_currentName;
	int m_currentSelect;
	Game *m_game;
	Player *m_player;
	void goToMenu();
	void goToSave();
	void getProfileName();
	void goToNewProfile();
	void loadFirstProfile();
	void loadSecondProfile();
	void loadThirdProfile();
	void loadFourthProfile();
	void loadFifthProfile();
	void loadSixthProfile();
	void loadSeventhProfile();
	void loadEighthProfile();
	void loadNinethProfile();
	void loadTenProfile();
//	void goToSpecs();
	std::string m_playerNames[10];
};

#endif // !CHANGEPROFILE