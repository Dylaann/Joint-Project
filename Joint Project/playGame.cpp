#include "playGame.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>



playGame::playGame(Game &game): 
	m_game(&game)
{
	// This is where buttons are created and assigned positions
	m_title = new Label("Map Select", 450, 30);
	m_mapSelection = new Button("Map **", 450, 250);
	// I assign each button to bring the player to a different gamestate when pressed
	moveRight = new Button("Map One", 200, 200);
	moveRight->getFocus();
	moveRight->Enter = std::bind(&playGame::goToSpecs, this);
	moveDowner = new Button("Map Two", 200, 250);
	moveDowner->Enter = std::bind(&playGame::goToSpecsMap2, this);
	goBack = new Button("Back", 200, 500);
	goBack->Enter = std::bind(&playGame::goToMenu, this);

	//Creates map one 
	sf::Texture& dayMapTexture = m_game->m_manager->m_textureHolder["dayLightMap"];
	dayMapSprite.setTexture(dayMapTexture);
	dayMapSprite.setPosition(0, 0);
	
	//Creates map two
	sf::Texture& nightMapTexture = m_game->m_manager->m_textureHolder["nightVisionMap"];
	nightMapSprite.setTexture(nightMapTexture);
	nightMapSprite.setPosition(0, 0);

	//adds all the buttons 
	m_gui.addButton(moveRight);
	m_gui.addButton(moveDowner);
	m_gui.addButton(goBack);
	m_gui.addLabel(m_title);
	m_currentSelect = 0;
	m_gui.vertical = true;
	m_title->changeTextSize(100);
	dayMapSprite.setPosition(400, 200);
	dayMapSprite.setScale(0.5, 0.5);
	nightMapSprite.setPosition(400, 200);
	nightMapSprite.setScale(0.5, 0.5);

}

playGame::~playGame()
{
}





void playGame::render(sf::RenderWindow & window)
 {
	/// Depending on what button is selected it will either draw one of the two maps 
	if (m_currentSelect == 0)
	{
		window.draw(dayMapSprite);
	}

	if (m_currentSelect == 1)
	{
		window.draw(nightMapSprite);
	}

	m_gui.draw(window);


}

void playGame::update()
{ 	
	m_gui.update(m_currentSelect, 3);
}


//Method that returns the player to the main menu
void playGame::goToMenu()
{
	m_game->changeGameState(GameState::TheMenu);
	
}
//Method that sends the player to the spec menu
void playGame::goToSpecs()
{
	m_game->m_nightMode->activateTheShader(false);
	m_game->changeGameState(GameState::Thespecs);

 }

void playGame::goToSpecsMap2()
{
	m_game->m_nightMode->activateTheShader(true);
	m_game->changeGameState(GameState::Thespecs);
}
