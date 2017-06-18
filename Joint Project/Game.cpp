#include <iostream>

#include "Game.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>


static double const MS_PER_UPDATE = 10.0;

/// <summary>
/// Game is constructed
/// </summary>
Game::Game() :
	m_window(sf::VideoMode(1280, 720), "Joint Project, Team C")
{

	// Load in level
	if (!LevelLoader::load(m_currentLevel))
	{
		return;
	}

	// resource manager
	m_manager = make_unique<ResourceManager>();

	// Loading in the car textures
	sf::Texture& m_startCar = m_manager->m_textureHolder["yellowCar"];
	sf::Texture& m_aistartCar = m_manager->m_textureHolder["blueCar"];

	// Shader
	sf::Texture& blankTexture = m_manager->m_textureHolder["blankBackground"];
	m_shaderSprite.setTexture(blankTexture);	// Set texture for the blank sprite
	if (!m_smokeShader.loadFromFile("Shaders/Smoke.frag", sf::Shader::Fragment)) //Load shader
	{
		std::cout << "shader failed to load" << std::endl;	// Error message
	}
	m_smokeShader.setParameter("time", 0.0f);
	m_smokeShader.setParameter("resolution", 1280.0f, 720.0f);
	m_shaderSprite.setPosition(0.0f, 0.0f);

	//Title
	m_text.setFont(m_font);
	m_text.setString("RACING GAME");
	m_text.setPosition(m_window.getSize().x / 4, m_window.getSize().y / 2);
	m_text.setCharacterSize(70);

	//initialise all the screens
	m_optionsScreen = make_unique<OptionsScreen>(*this);
	m_mapSelect = make_unique<playGame>(*this);
	m_soundScreen = make_unique<SoundScreen>(*this);
	m_displayScreen = make_unique<DisplayScreen>(*this);
	m_garageScreen = make_unique<GarageScreen>(m_window.getSize().x / 4, m_window.getSize().y / 2, *this);
	m_MainMenu = make_unique<MainMenu>(*this);
	m_helpScreen = make_unique<HelpScreen>(*this);
	m_Splash = make_unique<Splash>(*this);
	m_turboScreen = make_unique<TurboScreen>(*this);
	m_brakingScreen = make_unique<BrakingScreen>(*this);
	m_speedScreen = make_unique<SpeedScreen>(*this);
	m_accelerationScreen = make_unique<AccelerationScreen>(*this);
	m_Liscence = make_unique<Liscence>(*this);
	m_enterName = make_unique<EnterNameScreen>(*this, *m_player);
	m_credits = make_unique<Credits>(*this, m_currentLevel);
	m_cutscene = make_unique<Cutscene>(*this);
	m_gameOverScreen = make_unique<GameOverScreen>(*this);
	m_physicsBalls = make_unique<PhysicsBalls>(*this);
	// Car set up

	m_chooseCarScreen = make_unique<ChooseCar>(*this);
	//initialise AI/Player
	m_startPos = sf::Vector2f(m_window.getSize().x / 2, m_window.getSize().y / 4);
	m_car = make_unique<Car>(*this, m_startCar, m_startPos);
	m_aiCar = make_unique<Car>(*this, m_startCar, sf::Vector2f(760.0f, 1050.0f));
	m_aiCarTwo = make_unique<Car>(*this, m_startCar, sf::Vector2f(660.0f, 1050.0f));
	m_aiCarThree = make_unique<Car>(*this, m_startCar, sf::Vector2f(660.0f, 1100.0f));
	
	//Player
	m_player = make_unique<Player>(760.0f, 1100.0f, m_startCar, m_window, *this);

	//music
	m_buffer = m_manager->m_songHolder["IntroSong"];
	music.setBuffer(m_buffer);
	music.setLoop(true);
	music.setVolume(100);
	m_buffer2 = m_manager->m_songHolder["GameSong"];
	m_gameMusic.setBuffer(m_buffer2);
	m_gameMusic.setLoop(true);
	m_gameMusic.setVolume(100);
	


	/*  setup the views*/
	/*******************************************************************************/
	m_view = sf::View(sf::Vector2f(0, 0), sf::Vector2f(1280, 720));
	m_view2 = sf::View(sf::Vector2f(0, 0), sf::Vector2f(1280, 720));
	m_view2.setCenter(m_window.getSize().x / 2, m_window.getSize().y / 2);

	

	/*******************************************************************************/

	//more screens
	m_turboScreen = make_unique<TurboScreen>(*this);
	m_brakingScreen = make_unique<BrakingScreen>(*this);
	m_speedScreen = make_unique<SpeedScreen>(*this);
	m_accelerationScreen = make_unique<AccelerationScreen>(*this);
	m_changeProfile = make_unique<changeProfile>(*this, *m_player);
	m_saveProfile = make_unique<SaveScreen>(*this, *m_player);

	// Loading in the medium difficulty track
	for (int i = 0; i < m_currentLevel.m_mediumTrack.size(); i++)
	{
		sf::CircleShape circle(0, 30);
		circle.setRadius(m_currentLevel.m_mediumTrack[i].m_size);
		circle.setPosition(m_currentLevel.m_mediumTrack[i].m_position);
		m_mediumTrack.push_back(circle);
	}
	
	// Loading in the easy difficulty track
	for (int i = 0; i < m_currentLevel.m_easyTrack.size(); i++)
	{
		sf::CircleShape circle(0, 30);
		circle.setRadius(m_currentLevel.m_easyTrack[i].m_size);
		circle.setPosition(m_currentLevel.m_easyTrack[i].m_position);
		m_easyTrack.push_back(circle);
	}

	// Loading in the hard difficulty track
	for (int i = 0; i < m_currentLevel.m_hardTrack.size(); i++)
	{
		sf::CircleShape circle(0, 30);
		circle.setRadius(m_currentLevel.m_hardTrack[i].m_size);
		circle.setPosition(m_currentLevel.m_hardTrack[i].m_position);
		m_hardTrack.push_back(circle);
	}

	// Creating the ai players
	m_ai = make_unique< Ai>(*this, m_aiCar->getPos().x, m_aiCar->getPos().y, m_aistartCar, m_easyTrack);
	m_aiTwo = make_unique< Ai>(*this, m_aiCarTwo->getPos().x, m_aiCarTwo->getPos().y, m_aistartCar, m_mediumTrack);
	m_aiThree = make_unique< Ai>(*this, m_aiCarThree->getPos().x, m_aiCarThree->getPos().y, m_aistartCar, m_hardTrack);

	m_background = make_unique<Background>( *this);
	m_nightMode = make_unique<NightMode>(*this);
	
	m_level = make_unique<Levels>(m_currentLevel, *m_player, *m_ai, *m_aiTwo, *m_aiThree, *this);

	m_specs = make_unique< specs>(*this, *m_level);
	

}

/// <summary>
/// Initialise function
/// </summary>
void Game::init()
{
	// Display the list of all the video modes available for fullscreen
	vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
	timePerFrame = sf::seconds(1.0f / 60.0f);
}


/// <summary>
/// Game loop
/// </summary>
void Game::run()
{
	timeSinceLastUpdate = sf::Time::Zero;

	while (m_window.isOpen())
	{
		processInput();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame);
		}
		render();

	}
}


//check if sprites in view, return false if sprite not in view
//done by if the rectangle constructed by the view collides with the sprite
bool Game::isInView(sf::Sprite sprite)
{

	rect = sf::FloatRect(m_view.getCenter().x - (m_view.getSize().x/2), m_view.getCenter().y - (m_view.getSize().y/2), m_view.getSize().x, m_view.getSize().y);
	if (rect.intersects(sprite.getGlobalBounds()))
	{
		return true;
	}
	return false;
}

//return the best lap time from the race
std::string Game::getBestLapTime()
{
	return m_level->getBestLapTime();
}


//reset all the assets used in the the race
void Game::resetMap()
{
	m_level->resetLevel();
}

//find if the player won the race
bool Game::getPlayerPlace()
{
	return m_level->playerPos();
}

/// <summary>
/// Process Game inputs
/// </summary>
void Game::processInput()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		default:
			break;
		}
	}
}

/// <summary>
/// Update function
/// </summary>
void Game::update(sf::Time time)
{
	totalTime += timeSinceLastUpdate.asSeconds(); // Accumulative time

	//dont make car noises when not racing
	if (!m_currentGameState == GameState::Racing)
	{
		m_player->m_car.m_soundEffect.stop();
		m_player->m_car.m_speed = 0;
	}

	switch (m_currentGameState)
	{

	case GameState::TheOptions:
		m_optionsScreen->update();
		m_smokeShader.setParameter("time", totalTime);
		m_window.setView(m_view2);
		break;
	case GameState::TheMenu:
		m_MainMenu->update();
		m_smokeShader.setParameter("time", totalTime);
		m_window.setView(m_view2);
		break;
	case GameState::Difficulty:
		
		break;
	case GameState::Garage:
		m_garageScreen->update();
		m_smokeShader.setParameter("time", totalTime);
		m_window.setView(m_view2);
		break;
	case GameState::TheLicense:
		if (hasName == false)
		{
			m_player->setName(m_enterName->getEnteredName());
			hasName = true;
		}
		m_Liscence->update();
		m_window.setView(m_view2);
		break;
	case GameState::TheSplash:
		m_Splash->update();
		m_window.setView(m_view2);
		break;
	case GameState::Sound:
		m_soundScreen->update();
		m_smokeShader.setParameter("time", totalTime);
		m_window.setView(m_view2);
		break;
	case GameState::Display:
		m_displayScreen->update();
		m_smokeShader.setParameter("time", totalTime);
		m_window.setView(m_view2);
		break;
	case GameState::MapSelect:
		m_mapSelect->update();
		m_smokeShader.setParameter("time", totalTime);
		m_window.setView(m_view2);
		break;
	case GameState::Help:
		m_helpScreen->update();
		m_smokeShader.setParameter("time", totalTime);
		m_window.setView(m_view2);
		break;
	case GameState::Thespecs:
		m_specs->update();
		m_smokeShader.setParameter("time", totalTime);
		m_window.setView(m_view2);
		break;
	case GameState::Acceleration:
		m_accelerationScreen->update();
		m_smokeShader.setParameter("time", totalTime);
		m_window.setView(m_view2);
		break;
	case GameState::Braking:
		m_brakingScreen->update();
		m_smokeShader.setParameter("time", totalTime);
		m_window.setView(m_view2);
		break;
	case GameState::Speed:
		m_speedScreen->update();
		m_smokeShader.setParameter("time", totalTime);
		m_window.setView(m_view2);
		break;
	case GameState::Steering:
		
		break;
	case GameState::Turbo:
		m_turboScreen->update();
		m_smokeShader.setParameter("time", totalTime);
		m_window.setView(m_view2);
		break;
	case GameState::Racing:
		m_window.setView(m_view);
		m_level->update(time.asSeconds(), m_view);
		
		m_xbox.update();
		if (m_xbox.m_currentState.Start&& !m_xbox.m_previousState.Start)
		{
			m_background->activateTheShader();
		}
		
		break;
	case GameState::GameOver:
		m_gameOverScreen->update();
		m_window.setView(m_view2);
		break;
	case GameState::ChangeP:
		m_changeProfile->update();
		m_smokeShader.setParameter("time", totalTime);
		break;
	case GameState::Save:
		m_saveProfile->update();
		m_smokeShader.setParameter("time", totalTime);
		break;
	case GameState::EnterName:
		m_enterName->update();
		m_smokeShader.setParameter("time", totalTime);
		break;
	case GameState::TheCredits:
		m_credits->update();
		break;
	case GameState::CutsceneScreen:
		m_cutscene->update(totalTime);
		break;
	case GameState::PickCar:
		m_chooseCarScreen->update();
		break;
	default:
		break;

	}

}

/// <summary>
/// Render function
/// </summary>
void Game::render()
{


	switch (m_currentGameState)
	{

	case GameState::TheOptions:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(m_shaderSprite, &m_smokeShader);
		m_optionsScreen->render(m_window);
		m_window.display();
		break;
	case GameState::TheMenu:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(m_shaderSprite, &m_smokeShader);
		m_MainMenu->render(m_window);
		m_window.display();
		break;
	case GameState::Difficulty:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.display();
		break;
	case GameState::Garage:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(m_shaderSprite, &m_smokeShader);
		m_garageScreen->draw(m_window);
		m_window.display();
		break;
	case GameState::TheLicense:
		m_window.clear();
		m_Liscence->render(m_window);
		m_window.display();
		break;
	case GameState::TheSplash:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_Splash->render(m_window);
		m_window.display();
		break;
	case GameState::Sound:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(m_shaderSprite, &m_smokeShader);
		m_soundScreen->render(m_window);
		m_window.display();
		break;
	case GameState::Display:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(m_shaderSprite, &m_smokeShader);
		m_displayScreen->render(m_window);
		m_window.display();
		break;
	case GameState::MapSelect:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(m_shaderSprite, &m_smokeShader);
		m_mapSelect->render(m_window);
		m_window.display();
		break;
	case GameState::Help:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(m_shaderSprite, &m_smokeShader);
		m_helpScreen->draw(m_window);
		m_window.display();
		break;
	case GameState::Thespecs:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(m_shaderSprite, &m_smokeShader);
		m_specs->render(m_window);
		m_window.display();
		break;
	case GameState::Acceleration:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(m_shaderSprite, &m_smokeShader);
		m_accelerationScreen->draw(m_window);
		m_window.display();
		break;
	case GameState::Braking:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(m_shaderSprite, &m_smokeShader);
		m_brakingScreen->draw(m_window);
		m_window.display();
		break;
	case GameState::Speed:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(m_shaderSprite, &m_smokeShader);
		m_speedScreen->draw(m_window);
		m_window.display();
		break;
	case GameState::Steering:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.display();
		break;
	case GameState::Turbo:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(m_shaderSprite, &m_smokeShader);
		m_turboScreen->draw(m_window);
		m_window.display();
		break;
	case GameState::Racing:   //put in levels
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_background->draw(m_window);
		m_level->render(m_window);
		m_nightMode->draw(m_window);
		m_window.display();
		break;
	case GameState::GameOver:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(m_shaderSprite, &m_smokeShader);
		m_gameOverScreen->draw(m_window);
		m_window.display();
		break;

	case GameState::ChangeP:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(m_shaderSprite, &m_smokeShader);
		//nameDisplay(m_currentName);
		m_changeProfile->render(m_window);
	//	m_player->getName(m_name);

		m_window.display();
		break;
	case GameState::Save:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(m_shaderSprite, &m_smokeShader);
		m_saveProfile->render(m_window);
		m_window.display();
		break;
	case GameState::EnterName:
		m_window.clear(sf::Color(0, 0, 0, 255));
		m_window.draw(m_shaderSprite, &m_smokeShader);
		m_enterName->draw(m_window);
		m_window.display();
		break;
	case GameState::TheCredits:
		m_window.clear();
		m_credits->render(m_window);
		m_window.display();
		break;
	case GameState::CutsceneScreen:
		m_window.clear();
		m_cutscene->render(m_window);
		m_window.display();
		break;
	case GameState::PickCar:
		m_window.clear();
		m_window.draw(m_shaderSprite, &m_smokeShader);
		m_chooseCarScreen->draw(m_window);
		m_window.display();
		break;
	default:
		break;
	}


}

//function to change the games current gamestate
void Game::changeGameState(GameState gameState)
{
	m_currentGameState = gameState;
}


string Game::nameDisplay()
{
	return m_player->getName();
	/*m_name.setString("Profile");*/
}


int Game::playerMoney()
{
	return m_player->getMoney();
	
}

void Game::chargePlayer(int amount)
{
	m_player->cost(amount);
}

std::string Game::getGarageTexture()
{
	return m_currentLevel.m_garage.m_fileName;
}