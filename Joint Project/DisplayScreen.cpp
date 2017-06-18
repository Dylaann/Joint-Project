#include "DisplayScreen.h"
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
DisplayScreen::DisplayScreen(Game & game) :
	m_game(&game)
{
	m_speed = 100.0f;
	m_currentSelect = 0;

	// Title
	m_title = new Label("Display", 470, 50);	// Constructor
	m_title->changeTextSize(100);	// Resize and make it bigger
	m_gui.addLabel(m_title);	// Add to gui array

	// Animation on/off Checkbox
	m_animeOn = new CheckBox("Animations Off", 50, 150);	// Constructor
	m_animeOn->getFocus();	// Makes this button highlighted when the screen starts up
	//m_animeOn->getActive();	// Makes this button checked when the screen starts up
	m_gui.addCheckBox(m_animeOn);	// Add to gui array

	m_animeOn->Enter = std::bind(&DisplayScreen::animationOn, this);

	// Back button
	m_backButton = new Button("Back", 50, 600);	// Constructor
	m_backButton->Enter = std::bind(&DisplayScreen::setStateBack, this);	// Sets callback function to back method
	m_gui.addButton(m_backButton);	// Add to gui array

	m_gui.vertical = true;		// Enables vertical controls
}

/// <summary>
/// Deconstructor
/// </summary>
DisplayScreen::~DisplayScreen()
{
}

/// <summary>
/// Update loop
/// </summary>
void DisplayScreen::update()
{
	m_gui.update(m_currentSelect, 2);
}

/// <summary>
/// Draw loop
/// </summary>
/// <param name="window"></param>
void DisplayScreen::render(sf::RenderWindow & window)
{
	m_gui.draw(window);
}

/// <summary>
/// When the back button is pressed this method wil run
/// It will set the current state back to the options menu
/// </summary>
void DisplayScreen::setStateBack()
{
	m_game->changeGameState(GameState::TheOptions);
}

void DisplayScreen::animationOn()
{
	m_gui.useAnim =!(m_gui.useAnim);
}
