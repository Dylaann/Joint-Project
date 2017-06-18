#include "SoundScreen.h"
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
SoundScreen::SoundScreen(Game & game) :
	m_game(&game)
{
	m_volume = 100.0f;
	m_title = new Label("Sound", 475, 50);
	m_title->changeTextSize(100);

	
	m_musicVolume = new Slider(150.0f, 225.0f, m_volume, "Music volume");
	m_musicVolume->getFocus();
	m_musicVolume->AdjustAdd = std::bind(&SoundScreen::increaseMusicVol, this);
	m_musicVolume->AdjustMinus= std::bind(&SoundScreen::decreaseMusicVol, this);

	

	m_backButton = new Button("Back", 50, 600);
	m_backButton->Enter= std::bind(&SoundScreen::setStateBack, this);
	
	m_gui.addLabel(m_title);
	
	m_gui.addSlider(m_musicVolume);
	
	m_gui.addButton(m_backButton);
	m_currentSelect = 0;
	m_gui.vertical = true;	
}

/// <summary>
/// Deconstructor
/// </summary>
SoundScreen::~SoundScreen()
{
}

/// <summary>
/// Update loop
/// </summary>
void SoundScreen::update()
{
	m_gui.update(m_currentSelect, 2);
}

void SoundScreen::increaseMusicVol()
{
	if (m_volume < 100)
	{
		m_volume+=2;
	}
	m_game->m_gameMusic.setVolume(m_volume);
}

void SoundScreen::decreaseMusicVol()
{
	if (m_volume > 0)
	{
		m_volume-=2;
	}
	m_game->m_gameMusic.setVolume(m_volume);
}

/// <summary>
/// Draw loop
/// </summary>
/// <param name="window"></param>
void SoundScreen::render(sf::RenderWindow & window)
{
	m_gui.draw(window);
}

/// <summary>
/// When the back button is pressed this method will run
/// It will set the current state back to the options menu
/// </summary>
void SoundScreen::setStateBack()
{
	m_game->changeGameState(GameState::TheOptions);
}