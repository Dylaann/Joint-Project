#include "gameOverScreen.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

//construct the game over screen
GameOverScreen::GameOverScreen(Game & game):
	m_game(&game)
{
	//setup the widgets
	m_label = new Label("Game Over", 10, -80);
	m_label->changeTextSize(350);
	m_moneyEarned = new Label("Money earned: $1000", 60, 450);
	m_time = new Label("Time: ", 450, 450);
	m_placement = new Label("Place: ", 1000, 450);
	m_button = new Button("Return", 550, 650);
	m_button->Enter = std::bind(&GameOverScreen::goToGame, this); //bind the function
	m_button->getFocus();
	
	//add widgets to the gui
	m_gui.addLabel(m_label);
	m_gui.addLabel(m_moneyEarned);
	m_gui.addLabel(m_time);
	m_gui.addLabel(m_placement);
	m_gui.addButton(m_button);
	m_gui.vertical = true;
}

//draw the gui to the screen
void GameOverScreen::draw(sf::RenderWindow & window)
{
	m_gui.draw(window);
}

//update the gui and the labels text
void GameOverScreen::update()
{
	m_gui.update(m_selectedItem, 1);
	m_time->updateText(m_game->getBestLapTime()+ " seconds");
	if (m_game->getPlayerPlace()==true)
	{
		m_placement->updateText("You WON!!");
	}
	else
	{
		m_placement->updateText("You LOST!!");
	}
}

//return to the main menu
void GameOverScreen::goToGame()
{
	m_game->m_player->earned(1000);
	m_game->changeGameState(GameState::TheMenu);
}
