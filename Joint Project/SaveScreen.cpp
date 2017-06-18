#include "SaveScreen.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

SaveScreen::SaveScreen(Game &game, Player &player) :
	m_game(&game),
	m_player(&player)
{
	fileName = "players.txt";
	getProfileName();
	m_profileOne = new Button(m_playerNames[0], 450, 100);
	m_profileOne->Enter = std::bind(&SaveScreen::saveFirstProfile, this);
	m_profileOne->getFocus();
	m_profileTwo = new Button(m_playerNames[1], 450, 150);
	m_profileTwo->Enter = std::bind(&SaveScreen::saveSecondProfile, this);
	m_profileThree = new Button(m_playerNames[2], 450, 200);
	m_profileThree->Enter = std::bind(&SaveScreen::saveThirdProfile, this);
	m_profileFour = new Button(m_playerNames[3], 450, 250);
	m_profileFour->Enter = std::bind(&SaveScreen::saveFourthProfile, this);
	m_profileFive = new Button(m_playerNames[4], 450, 300);
	m_profileFive->Enter = std::bind(&SaveScreen::saveFifthProfile, this);
	m_profileSix = new Button(m_playerNames[5], 450, 350);
	m_profileSix->Enter = std::bind(&SaveScreen::saveSixthProfile, this);
	m_profileSeven = new Button(m_playerNames[6], 450, 400);
	m_profileSeven->Enter = std::bind(&SaveScreen::saveSeventhProfile, this);
	m_profileEight = new Button(m_playerNames[7], 450, 450);
	m_profileEight->Enter = std::bind(&SaveScreen::saveEighthProfile, this);
	m_profileNine = new Button(m_playerNames[8], 450, 500);
	m_profileNine->Enter = std::bind(&SaveScreen::saveNinethProfile, this);
	m_profileTen = new Button(m_playerNames[9], 450, 550);
	m_profileTen->Enter = std::bind(&SaveScreen::saveTenthProfile, this);
	m_Back = new Button("Back", 100, 500);
	m_Back->Enter = std::bind(&SaveScreen::goToChangeProfile, this);

	m_gui.addButton(m_profileOne);
	m_gui.addButton(m_profileTwo);
	m_gui.addButton(m_profileThree);
	m_gui.addButton(m_profileFour);
	m_gui.addButton(m_profileFive);
	m_gui.addButton(m_profileSix);
	m_gui.addButton(m_profileSeven);
	m_gui.addButton(m_profileEight);
	m_gui.addButton(m_profileNine);
	m_gui.addButton(m_profileTen);
	m_gui.addButton(m_Back);

	m_currentSelect = 0;
	m_gui.vertical = true;

	
}

SaveScreen::~SaveScreen()
{

}

void SaveScreen::render(sf::RenderWindow & window)
{
	m_gui.draw(window);

}

void SaveScreen::update()
{
	m_gui.update(m_currentSelect, 11);
}

void SaveScreen::saveFirstProfile()
{
	m_player->save(m_playerNames[0]);
	m_game->changeGameState(GameState::TheMenu);
}

void SaveScreen::saveSecondProfile()
{
	m_player->save(m_playerNames[1]);
	m_game->changeGameState(GameState::TheMenu);
}

void SaveScreen::saveThirdProfile()
{
	m_player->save(m_playerNames[2]);
	m_game->changeGameState(GameState::TheMenu);
}

void SaveScreen::saveFourthProfile()
{
	m_player->save(m_playerNames[3]);
	m_game->changeGameState(GameState::TheMenu);
}

void SaveScreen::saveFifthProfile()
{
	m_player->save(m_playerNames[4]);
	m_game->changeGameState(GameState::TheMenu);
}

void SaveScreen::saveSixthProfile()
{
	m_player->save(m_playerNames[5]);
	m_game->changeGameState(GameState::TheMenu);
}

void SaveScreen::saveSeventhProfile()
{
	m_player->save(m_playerNames[6]);
	m_game->changeGameState(GameState::TheMenu);
}

void SaveScreen::saveEighthProfile()
{
	m_player->save(m_playerNames[7]);
	m_game->changeGameState(GameState::TheMenu);
}

void SaveScreen::saveNinethProfile()
{
	m_player->save(m_playerNames[8]);
	m_game->changeGameState(GameState::TheMenu);
}

void SaveScreen::saveTenthProfile()
{
	m_player->save(m_playerNames[9]);
	m_game->changeGameState(GameState::TheMenu);
}

void SaveScreen::goToMenu()
{
	m_game->changeGameState(GameState::TheMenu);
}

void SaveScreen::goToChangeProfile()
{
	m_game->changeGameState(GameState::ChangeP);
}

void SaveScreen::getProfileName()
{
	fileInput.open(fileName);					// Open the input file

	for (int i = 0; i < 10; i++)
	{
		fileInput >> fileLine;				// Get the next line
		m_playerNames[i] = fileLine;		// Give the player this name

											//Skip the date for this player we only want the name
		fileInput >> fileLine;				// Get the next line 
		fileInput >> fileLine;				// Get the next line
		fileInput >> fileLine;				// Get the next line
	}

	fileInput.close();					// Close the input file

}