#include "DifficultyScreen.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

DifficultyScreen::DifficultyScreen(Game & game):
	m_game(&game)
{
	m_selectedItem = 0;

	// Easy button
	m_widgets[0] = new RadioButton("easy", 550, 250, "diff");
	m_widgets[0]->getFocus();
	m_widgets[0]->Enter = std::bind(&DifficultyScreen::setEasy, this);

	// Medium button
	m_widgets[1] = new RadioButton("medium", 550, 350, "diff");
	m_widgets[1]->getActive();
	m_widgets[1]->Enter = std::bind(&DifficultyScreen::setMedium, this);

	// Hard button
	m_widgets[2] = new RadioButton("hard", 550, 450, "diff");
	m_widgets[2]->Enter = std::bind(&DifficultyScreen::setHard, this);

	// Back button
	m_widgets[3] = new Button("Back", 550, 550);
	m_widgets[3]->Enter = std::bind(&DifficultyScreen::goToOptions, this);

	// Adds each widget to the gui
	for each (Widget* var in m_widgets)
	{
		m_gui.addWidget(var);
	}

	// Enables vertical controls
	m_gui.vertical = true;

	
}

/// <summary>
/// Render loop
/// </summary>
/// <param name="window"></param>
void DifficultyScreen::render(sf::RenderWindow & window)
{
	m_gui.draw(window);	//Render all gui objects
}

/// <summary>
/// Update loop
/// </summary>
void DifficultyScreen::update()
{
	m_gui.update(m_selectedItem, MAX_ITEMS);	// Update all gui objects
}

/// <summary>
/// Used as a callback function to change the gamestate to the options screen
/// </summary>
void DifficultyScreen::goToOptions()
{
	m_game->changeGameState(GameState::TheOptions);	// Change the gamestate the options screen
}

/// <summary>
/// Used as a callback function
/// Changes the difficulty of the game to easy
/// </summary>
void DifficultyScreen::setEasy()
{
	//m_game->changeGameDifficulty(GameDifficulty::Easy);	// Change the difficulty of the game to easy
}

/// <summary>
/// Used as a callback function
/// Changes the difficulty of the game to medium
/// </summary>
void DifficultyScreen::setMedium()
{
	//m_game->changeGameDifficulty(GameDifficulty::Medium);	// Change the difficulty of the game to medium
}

/// <summary>
/// Used as a callback function
/// Changes the difficulty of the game to hard
/// </summary>
void DifficultyScreen::setHard()
{
//	m_game->changeGameDifficulty(GameDifficulty::Hard);	// Change the difficulty of the game to hard
}
