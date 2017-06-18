#include "changeProfile.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>


changeProfile::changeProfile(Game &game, Player &player) :
	m_game(&game),
	m_player(&player)
{
	filename = "players.txt";
	getProfileName();
	m_profileOne = new Button(m_playerNames[0], 450, 100);
	m_profileOne->Enter = std::bind(&changeProfile::loadFirstProfile, this);
	m_profileOne->getFocus();
	m_profileTwo = new Button(m_playerNames[1], 450, 150);
	m_profileTwo->Enter = std::bind(&changeProfile::loadSecondProfile, this);
	m_profileThree = new Button(m_playerNames[2], 450, 200);
	m_profileThree->Enter = std::bind(&changeProfile::loadThirdProfile, this);
	m_profileFour = new Button(m_playerNames[3], 450, 250);
	m_profileFour->Enter = std::bind(&changeProfile::loadFourthProfile, this);
	m_profileFive = new Button(m_playerNames[4], 450, 300);
	m_profileFive->Enter = std::bind(&changeProfile::loadFifthProfile, this);
	m_profileSix = new Button(m_playerNames[5], 450, 350);
	m_profileSix->Enter = std::bind(&changeProfile::loadSixthProfile, this);
	m_profileSeven = new Button(m_playerNames[6], 450, 400);
	m_profileSeven->Enter = std::bind(&changeProfile::loadSeventhProfile, this);
	m_profileEight = new Button(m_playerNames[7], 450, 450);
	m_profileEight->Enter = std::bind(&changeProfile::loadEighthProfile, this);
	m_profileNine = new Button(m_playerNames[8], 450, 500);
	m_profileNine->Enter = std::bind(&changeProfile::loadNinethProfile, this);
	m_profileTen = new Button(m_playerNames[9], 450, 550);
	m_profileTen->Enter = std::bind(&changeProfile::loadTenProfile, this);
	m_Back = new Button("Back", 100, 500);
	m_Back->Enter = std::bind(&changeProfile::goToMenu, this);
	m_Save = new Button("Save", 100, 550);
	m_Save->Enter = std::bind(&changeProfile::goToSave, this);
	m_New = new Button("New Profile", 100, 600);
	m_New->Enter = std::bind(&changeProfile::goToNewProfile, this);
	//m_currentName = new Label(name, 50, 30);

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
	m_gui.addButton(m_Save);
	m_gui.addButton(m_New);
	m_currentSelect = 0;
	m_gui.vertical = true;
}


changeProfile::~changeProfile()
{

}


void changeProfile::render(sf::RenderWindow & window)
{
	m_gui.draw(window);

}


void changeProfile::update()
{
	m_gui.update(m_currentSelect, 13);
}

void changeProfile::loadFirstProfile()
{
	m_player->load(m_playerNames[0]);
	m_game->changeGameState(GameState::TheMenu);
}

void changeProfile::loadSecondProfile()
{
	m_player->load(m_playerNames[1]);
	m_game->changeGameState(GameState::TheMenu);
}

void changeProfile::loadThirdProfile()
{
	m_player->load(m_playerNames[2]);
	m_game->changeGameState(GameState::TheMenu);
}

void changeProfile::loadFourthProfile()
{
	m_player->load(m_playerNames[3]);
	m_game->changeGameState(GameState::TheMenu);
}

void changeProfile::loadFifthProfile()
{
	m_player->load(m_playerNames[4]);
	m_game->changeGameState(GameState::TheMenu);
}

void changeProfile::loadSixthProfile()
{
	m_player->load(m_playerNames[5]);
	m_game->changeGameState(GameState::TheMenu);
}

void changeProfile::loadSeventhProfile()
{
	m_player->load(m_playerNames[6]);
	m_game->changeGameState(GameState::TheMenu);
}

void changeProfile::loadEighthProfile()
{
	m_player->load(m_playerNames[7]);
	m_game->changeGameState(GameState::TheMenu);
}

void changeProfile::loadNinethProfile()
{
	m_player->load(m_playerNames[8]);
	m_game->changeGameState(GameState::TheMenu);
}

void changeProfile::loadTenProfile()
{
	m_player->load(m_playerNames[9]);
	m_game->changeGameState(GameState::TheMenu);
}

void changeProfile::goToMenu()
{
	m_game->changeGameState(GameState::TheMenu);
}

void changeProfile::goToNewProfile()
{
	m_game->changeGameState(GameState::EnterName);
}

void changeProfile::goToSave()
{
	m_game->changeGameState(GameState::Save);
}


void changeProfile::getProfileName()
{
	fileInput.open(filename);					// Open the input file

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