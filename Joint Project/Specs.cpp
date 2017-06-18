#include "Specs.h"
#include "playGame.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

specs::specs(Game &game, Levels &level):
	m_game(&game),
	m_currentLevel(&level)
{
	m_currentLevel->m_maxLaps = 3;
	m_EnemiesNum = 100.0f;
	m_title = new Label("Specifications", 400, 30);
	m_Race = new Button("Play", 550, 450);
	m_Race->Enter = std::bind(&specs::goToMapRacing, this);
	m_Back = new Button("Back", 550, 500);
	m_Back->Enter = std::bind(&specs::goToMapSelect, this);
	m_3 = new RadioButton("3 Laps", 550, 150,"laps");
	m_3->getActive();
	m_3->getFocus();
	m_3->Enter = std::bind(&specs::goToLapSelect3, this);
	m_5 = new RadioButton("5 Laps", 550, 200,"laps");
	m_5->Enter = std::bind(&specs::goToLapSelect5, this);
	m_7 = new RadioButton("7 Laps", 550, 250,"laps");
	m_7->Enter = std::bind(&specs::goToLapSelect7, this);

	m_title->changeTextSize(100);
	m_gui.addRadioButton(m_3);
	m_gui.addRadioButton(m_5);
	m_gui.addRadioButton(m_7);
	m_gui.addButton(m_Race);
	m_gui.addButton(m_Back);
	
	m_currentSelect = 0;
	m_gui.vertical = true;
}

specs::~specs()
{
}

void specs::render(sf::RenderWindow & window)
{
	m_gui.draw(window);
}

void specs::update()
{
	m_gui.update(m_currentSelect, 5);
}

void specs::goToMapSelect()
{
	m_game->changeGameState(GameState::MapSelect);

}

void specs::goToMapRacing()
{
	m_game->resetMap();
	m_game->changeGameState(GameState::Racing);
}

void specs::goToLapSelect3()
{
	m_currentLevel->m_maxLaps = 3;
}

void specs::goToLapSelect5()
{
	m_currentLevel->m_maxLaps = 5;
}

void specs::goToLapSelect7()
{
	m_currentLevel->m_maxLaps = 7;
}


