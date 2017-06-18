#pragma once
#ifndef GARAGESCREEN
#define GARAGESCREEN
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

#include"GUI.h"
#include"Game.h"



//Garage is where upgrades and customisation on the players car is done
class GarageScreen {
public:
	GarageScreen(float x, float y, Game& game); //constructor
	void update(); //update loop
	void draw(sf::RenderWindow &window); //draw loop 
	void goBack();   //go to gamestate menu
	void goAccel();	 //go to gamestate acceleration
	void goTurbo();	 //go to gamestate turbo
		 //go to gamestate braking
	void goSpeed();	 //go to gamestate speed
	void goSteer();	 //go to gamestate steering

private:
	int m_selectedItem = 0;
	//widgets
	static const int MAX_ITEMS = 5;
	Widget* m_widgets[MAX_ITEMS];
	Label* m_label;
	GUI m_gui; //gui

	Game *m_game;
};
#endif // !GARAGESCREEN