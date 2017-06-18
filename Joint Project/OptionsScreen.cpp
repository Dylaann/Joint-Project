#include "OptionsScreen.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

/// <summary>
/// Constructor
/// </summary>
/// <param name="game"></param>
OptionsScreen::OptionsScreen(Game & game) :
	m_game(&game)
{
	m_title = new Label("Options", 475, 50);
	/*m_difficultyButton = new Button("Difficulty", 550, 250);
	m_difficultyButton->getFocus();
	m_difficultyButton->Enter = std::bind(&OptionsScreen::setStateDifficulty, this);*/
	m_soundButton = new Button("Sound", 570, 250);
	m_soundButton->Enter = std::bind(&OptionsScreen::setStateSound, this);
	m_soundButton->getFocus();
	m_displayButton = new Button("Display", 565, 350);
	m_displayButton->Enter = std::bind(&OptionsScreen::setStateDisplay, this);
	m_backButton = new Button("Back", 575, 450);
	m_backButton->Enter = std::bind(&OptionsScreen::setStateBack, this);
	//m_gui.addButton(m_difficultyButton);
	m_gui.addButton(m_soundButton);
	m_gui.addButton(m_displayButton);
	m_gui.addButton(m_backButton);
	m_gui.addLabel(m_title);
	m_currentSelect = 0;
	m_gui.vertical = true;
	m_title->changeTextSize(100);
}

/// <summary>
/// Deconstructor
/// </summary>
OptionsScreen::~OptionsScreen()
{
}

/// <summary>
/// Draw loop
/// </summary>
/// <param name="window"></param>
void OptionsScreen::render(sf::RenderWindow & window)
{
	m_gui. draw(window);
}

/// <summary>
/// Update loop
/// </summary>
void OptionsScreen::update()
{
	m_gui.update(m_currentSelect,3);
}

/// <summary>
/// When the difficulty button is pressed
/// Bring the user to the difficulty screen
/// </summary>
void OptionsScreen::setStateDifficulty()
{
	m_game->changeGameState(GameState::Difficulty);
}

/// <summary>
/// When the display button is pressed
/// Bring the user to the display screen
/// </summary>
void OptionsScreen::setStateDisplay()
{
	m_game->changeGameState(GameState::Display);
}

/// <summary>
/// When the sound button is pressed
/// Bring the user to the sound screen
/// </summary>
void OptionsScreen::setStateSound()
{
	m_game->changeGameState(GameState::Sound);
}

/// <summary>
/// When the back button is pressed
/// Bring the player back to the main menu
/// </summary>
void OptionsScreen::setStateBack()
{
	m_game->changeGameState(GameState::TheMenu);
}