#include "Help.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

//construct the help screen
HelpScreen::HelpScreen(Game & game):
	m_game(&game)
{
	//setup widgets
	m_label = new Label("Drift", 50, 50, "a button.png");
	m_label2 = new Label("Turbo", 50, 100, "y button.png");
	m_label3 = new Label("Steer", 50, 150, "left analog.png");
	m_label4 = new Label("Accelerate", 50, 200, "right trigger.png");
	m_label5 = new Label("Reverse", 50, 250, "left trigger.png");
	m_backButton = new Button("Back", 50, 720 / 2);
	m_backButton->getFocus();
	m_backButton->Enter = std::bind(&HelpScreen::goBack, this); //bind function
	
	//add widgets to gui
	m_gui.addButton(m_backButton);
	m_gui.addLabel(m_label);
	m_gui.addLabel(m_label2);
	m_gui.addLabel(m_label3);
	m_gui.addLabel(m_label4);
	m_gui.addLabel(m_label5);
	m_gui.vertical = true;
}

//update gui obect
void HelpScreen::update()
{
	m_gui.update(m_selectedItem, 1);
}

//draw the gui object
void HelpScreen::draw(sf::RenderWindow & window)
{
	m_gui.draw(window);
}

//go back to the menu gamestate
void HelpScreen::goBack()
{
	m_game->changeGameState(GameState::TheMenu);
}
