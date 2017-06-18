#include "MainMenu.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

//construct the main menu screen
MainMenu::MainMenu(Game &game):
	m_game(&game)
{
	//setup all the widgets
	m_title = new Label("Team C Racing", 180, 50, "menuPic.png", "menuPic.png");
	m_title->setUnderLined();
	m_gui.addLabel(m_title);
	m_Play = new Button("Play", 550, 250);
	m_Play->getFocus();
	m_Play->Enter = std::bind(&MainMenu::goToPlay, this);
	m_Garage = new Button("Garage", 550, 300);
	m_Garage->Enter = std::bind(&MainMenu::GotoGarage, this);
	m_ChangeProfile = new Button("Change Profile", 550, 350);
	m_ChangeProfile->Enter = std::bind(&MainMenu::goToChangeP, this);
	m_Options = new Button("Options", 550, 400);
	m_Options->Enter = std::bind(&MainMenu::goToOptions, this);
	m_Help = new Button("Help", 550, 450);
	m_Help->Enter = std::bind(&MainMenu::goToHelp, this);
	m_Credits = new Button("Credits", 550, 500);
	m_Credits->Enter = std::bind(&MainMenu::goToCredits, this);
	m_Exit = new Button("Quit", 550, 550);
	m_Exit->Enter = std::bind(&MainMenu::quit, this);

	m_icons[0] = new Label("Select", 20, 650, "a button.png");
	m_icons[1] = new Label("Move", 170, 650, "d pad.png");

	//add widgets to the gui
	m_gui.addButton(m_Play);
	m_gui.addButton(m_Garage);
	m_gui.addButton(m_ChangeProfile);
	m_gui.addButton(m_Options);
	m_gui.addButton(m_Help);
	m_gui.addButton(m_Credits);
	m_gui.addButton(m_Exit);
	m_gui.addLabel(m_icons[0]);
	m_gui.addLabel(m_icons[1]);

	m_currentSelect = 0;
	m_gui.vertical = true;
	m_title->changeTextSize(100);

};


MainMenu::~MainMenu()
{
}

//draw the gui object
void MainMenu::render(sf::RenderWindow & window)
{
	m_gui.draw(window);
}

//update the gui object
void MainMenu::update()
{
	m_gui.update(m_currentSelect, 7);
}

//go to the garage screen
void MainMenu::GotoGarage()
{
	m_game->changeGameState(GameState::PickCar);
}

//close the application
void MainMenu::quit()
{
	m_game->m_window.close();
}

//go to the options screen
void MainMenu::goToOptions()
{
	m_game->changeGameState(GameState::TheOptions);
}

//go the map select screen
void MainMenu::goToPlay()
{
	m_game->changeGameState(GameState::MapSelect);
}

//go to the help screen
void MainMenu::goToHelp()
{
	m_game->changeGameState(GameState::Help);
}

//go to the specs screen
void MainMenu::goToSpecs()
{

	m_game->changeGameState(GameState::Thespecs);

}
//go to the change profile screen
void MainMenu::goToChangeP()
{

	m_game->changeGameState(GameState::ChangeP);

}
//go to the credits screen
void MainMenu::goToCredits()
{
	m_game->changeGameState(GameState::TheCredits);
}
