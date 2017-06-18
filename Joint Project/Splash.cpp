#include "Splash.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

//constructs the splash screen
Splash::Splash(Game & game) : m_game(&game)
{
	load();
	m_animation.fit(sf::FloatRect(0, 0, 1280, 720), true);
	m_animation.setVolume(100);

	m_currentSelect = 0;
	m_button = new Button("Press A", 560, 600);
	m_button->getFocus();
	m_button->Enter = std::bind(&Splash::setStateBack, this);
	m_gui.addButton(m_button);

	m_gui.vertical = true;
	
}

//destructor
Splash::~Splash()
{
}

//updates screen
void Splash::update()
{
	if (m_play == true)
	{
		m_animation.play();
	}

	m_animation.update();
	m_play = false;


	if (m_animation.getPlayingOffset().asSeconds() >= 7)
	{
		m_animation.pause();
		m_gui.update(m_currentSelect, 1);
	}
}

//draws window
void Splash::render(sf::RenderWindow & window)
{
		window.draw(m_animation);
		m_gui.draw(window);
}

void Splash::load()
{
	if (!m_animation.openFromFile("SplashScreenS.mp4"))
	{
		cout << "splash not loaded" << endl;
	}
}

//sets gamestate
void Splash::setStateBack()
{
	m_animation.~Movie();
	m_game->music.stop();
	m_game->m_gameMusic.play();
	m_game->changeGameState(GameState::TheMenu);
}
