/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

#ifndef MAINMENU
#define MAINMENU

#include "GUI.h"
#include "Button.h"
#include"Game.h"


class Game;
///<summary>
// This class will create and manage the main menu screen
///<summary>
class MainMenu
{
public:

	MainMenu(Game &game);
	~MainMenu();
	void render(sf::RenderWindow & window); //draw loop 
	void update(); //update loop
	void GotoGarage(); // go the garage menu
	void quit(); //quit the game
	void goToOptions(); //go to the options menu
	void goToPlay(); //go to the play menu
	void goToHelp(); //go to the help screen
	void goToSpecs(); //go to the specs screen
	void goToChangeP(); //go to the change profile screen
	void goToCredits(); //go to the credits screen

private:

	GUI m_gui; //gui object
	//widgets
	Label *m_title; 
	Label *m_icons[2];
	Button *m_Play;
	Button *m_Garage;
	Button *m_ChangeProfile;
	Button *m_Options;
	Button *m_Help;
	Button *m_Exit;
	Button *m_Credits;
	int m_currentSelect; //index
	Game *m_game; //game object
};
#endif // !MAINMENU