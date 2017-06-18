#include "Credits.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

//creates credits screen
Credits::Credits(Game & game, LevelData &level) : m_game(&game),
												m_currentLevel(&level)
{
	load();
	m_credits.fit(sf::FloatRect(0,0, 1280, 720), true);
	m_credits.setVolume(100);
	
}

//destructor
Credits::~Credits()
{
}

//updates, displays animations
void Credits::update()
{
	m_game->m_gameMusic.pause();

	if (m_play == true)
	{
		m_credits.play();
	}

	m_credits.update();
	m_play = false;
	
	
	if (m_credits.getStatus() == 0)
	{
		m_play = true;
		m_game->m_gameMusic.play();
		m_game->changeGameState(GameState::TheMenu);
	}
}

//render funtion
void Credits::render(sf::RenderWindow & window)
{
	if (m_credits.getStatus() == 2)
	{
		window.draw(m_credits);
	}
}

//load animation
void Credits::load()
{
	if (!m_credits.openFromFile(m_currentLevel->m_credits.m_fileName))
	{
		cout << "credits not loaded" << endl;
	}
}

