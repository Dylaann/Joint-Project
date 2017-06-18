#pragma once
#ifndef ENTERNAME
#define ENTERNAME
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

#include "Game.h"
#include "GUI.h"
class Game;

//the screen where the player can enter their name using buttons
class EnterNameScreen {
public:
	EnterNameScreen(Game &game, Player &player); //constructor
	std::string getEnteredName(); //return the entered in name
	void update(); //update loop
	void draw(sf::RenderWindow &window); //draw loop

	void addQ(); //add the chosen letter to the string name
	void addW();
	void addE();
	void addR();
	void addT();
	void addY();
	void addU();
	void addI();
	void addO();
	void addP();
	void addA();
	void addS();
	void addD();
	void addF();
	void addG();
	void addH();
	void addJ();
	void addK();
	void addL();
	void addZ();
	void addX();
	void addC();
	void addV();
	void addB();
	void addN();
	void addM();
	void addChar();
	void Space();
	void deleteLetter(); //delete last character
	void add$();
private:
	static const int MAX_ITEMS = 30; //amount of widgets
	GUI m_gui; //gui
	Widget* m_widgets[MAX_ITEMS]; //widgets
	Label *m_label; //labels
	Label *m_enter;
	std::string m_enteredName; //the new name of the player
	int m_selectedItem = 0;
	Game *m_game;
	Player *m_player;
	Xbox360Controller m_xbox;
	sf::Clock m_clock;
	bool startClock = false;
};
#endif // !ENTERNAME