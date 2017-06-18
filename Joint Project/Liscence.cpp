#include "Liscence.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

//creates the screen
Liscence::Liscence(Game & game) : m_game(&game)
{

	load();
	m_animation.fit(sf::FloatRect(0, 0, 1280, 720), true);
	m_animation.setVolume(100);
}

//destructor
Liscence::~Liscence()
{
}

//Displays the lisence animation then switches to splash screen
void Liscence::update()
{

	m_game->music.pause();
	m_game->m_gameMusic.pause();

	if (m_play == true)
	{
		m_animation.play();
	}

	m_animation.update();
	m_play = false;

	if (m_animation.getStatus() == 0)
	{

		m_game->music.play();
		m_animation.~Movie();
		m_game->changeGameState(GameState::TheSplash);
	}
}

//draws the screen
void Liscence::render(sf::RenderWindow & window)
{
	if (m_animation.getStatus() == 2)
	{
		window.draw(m_animation);
	}
}

void Liscence::load()
{
	if (!m_animation.openFromFile("Final animation.mp4"))
	{
		cout << "lisence not loaded" << endl;
	}
}

