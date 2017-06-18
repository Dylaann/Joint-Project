#include "BrakingScreen.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

//construct the screen object
BrakingScreen::BrakingScreen(Game & game):
	m_game(&game)
{
	sf::Texture& texture = m_game->m_manager->m_textureHolder["garage"];//load
	//setup sprite
	m_sprite.setTexture(texture);

	m_sprite.setTextureRect(sf::IntRect(168, 521, 200, 200));
	m_sprite.setPosition(600, 300);

	//setup widgets
	m_label = new Label("Braking", 100, 50);
	m_label->setUnderLined();
	m_label->changeTextSize(70);
	m_gui.addLabel(m_label);
	m_playerMoney = new Label("Money: ", 750, 50);
	m_playerMoney->setUnderLined();
	m_playerMoney->changeTextSize(30);
	m_gui.addLabel(m_playerMoney);
	m_widgets[0] = new Button("Small (500)", 100, 150);
	m_widgets[0]->getFocus();
	m_widgets[0]->Enter = std::bind(&BrakingScreen::smallBuy, this);
	m_widgets[1] = new Button("Medium (2500)", 100, 250);
	m_widgets[1]->Enter = std::bind(&BrakingScreen::mediumBuy, this);
	m_widgets[2] = new Button("Large (5000)", 100, 350);
	m_widgets[2]->Enter = std::bind(&BrakingScreen::largeBuy, this);
	m_widgets[3] = new Button("Back", 100, 450);
	m_widgets[3]->Enter = std::bind(&BrakingScreen::goToGarage, this); //bind the functions

	for each (Widget* var in m_widgets)
	{
		m_gui.addWidget(var); //add widgets to gui
	}
	m_gui.vertical = true;

}
//draw assets and gui to the screen
void BrakingScreen::draw(sf::RenderWindow &window)
{
	m_gui.draw(window);
	window.draw(m_sprite);
}

//update the players cash balance and the gui object
void BrakingScreen::update()
{
	m_playerMoney->updateText("Money: " + std::to_string(m_game->playerMoney()));
	m_gui.update(m_selectedItem, MAX_ITEMS);
}

//for purchasing small upgrade, charge applied and money removed from the player
void BrakingScreen::smallBuy()
{
	if (m_game->playerMoney() >= SMALL_PRICE && !m_smallBought)
	{
		m_smallBought = true;
		m_game->chargePlayer(SMALL_PRICE);
	}

	if (m_smallBought)
	{
		m_smallEquipped = true;
		m_mediumEquipped = false;
		m_largeEquipped = false;
		m_sprite.setScale(1.25, 1.25);
	}
}
//for purchasing medium upgrade, charge applied and money removed from the player
void BrakingScreen::mediumBuy()
{
	if (m_game->playerMoney() >= MEDIUM_PRICE && !m_mediumBought)
	{
		m_mediumBought = true;
		m_game->chargePlayer(MEDIUM_PRICE);
	}

	if (m_mediumBought)
	{
		m_smallEquipped = false;
		m_mediumEquipped = true;
		m_largeEquipped = false;
		m_sprite.setScale(1.5, 1.5);
	}
}

//for purchasing large upgrade, charge applied and money removed from the player
void BrakingScreen::largeBuy()
{
	if (m_game->playerMoney() >= LARGE_PRICE && !m_largeBought)
	{
		m_largeBought = true;
		m_game->chargePlayer(LARGE_PRICE);
	}

	if (m_largeBought)
	{
		m_smallEquipped = false;
		m_mediumEquipped = false;
		m_largeEquipped = true;
		m_sprite.setScale(1.75, 1.75);
	}
}

//go to garage gamestate
void BrakingScreen::goToGarage()
{
	m_game->changeGameState(GameState::Garage);
}
