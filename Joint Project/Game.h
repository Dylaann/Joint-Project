#ifndef GAME
#define GAME
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

#include <Thor\Resources.hpp>
#include "include\sfeMovie\Movie.hpp"
#include "include\sfeMovie\Visibility.hpp"
#include "include\sfeMovie\StreamSelection.hpp"
#include <sfeMovie\Visibility.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include <SFML\Graphics\Rect.hpp>
#include "OptionsScreen.h"
#include "playGame.h"
#include "SoundScreen.h"
#include "MainMenu.h"
#include "GarageScreen.h"
#include "DisplayScreen.h"
#include "Player.h"
#include "Help.h"
#include "Liscence.h"
#include "Splash.h"
#include "TurboScreen.h"
#include "BrakingScreen.h"
#include "SpeedScreen.h"
#include "AccelerationScreen.h"
#include "Car.h"
#include "XBOX360CONTROLLER.h"
#include "Specs.h"
#include "Liscence.h"
#include "Splash.h"
#include "DifficultyScreen.h"
#include "SteeringScreen.h"
#include "TurboScreen.h"
#include "BrakingScreen.h"
#include "SpeedScreen.h"
#include "AccelerationScreen.h"
#include "changeProfile.h"
#include "LevelLoad.h"
#include "ResourceManager.h"
#include "levels.h"
#include "Ai.h"
#include "EnterNameScreen.h"
#include <SFML\Audio.hpp>
#include "background.h"
#include "NightMode.h"
#include "Credits.h"
#include <memory>
#include "gameOverScreen.h"
#include "SaveScreen.h"
#include "PhysicsBalls.h"
#include "chooseCar.h"
#include "Cutscene.h"

using namespace std;
class SoundScreen;
class DisplayScreen;
class OptionsScreen;
class Liscence;
class Splash;
class MainMenu;
class GarageScreen;
class HelpScreen;
class Player;
class Ai;
class TurboScreen;
class BrakingScreen;
class SpeedScreen;
class AccelerationScreen;
class specs;
class playGame;
class changeProfile;
class Levels;
class EnterNameScreen;
class Background;
class Player;
class Credits;
class NightMode;
class GameOverScreen;
class SaveScreen;
class PhysicsBalls;
class ChooseCar;
class Cutscene;


//each case in this enum represents a screen
enum GameState {
	TheLicense,
	TheSplash,
	TheMenu,
	TheOptions,
	Display,
	Difficulty,
	Sound,
	Garage,
	MapSelect,
	Help,
	Thespecs,
	Acceleration,
	Speed,
	Braking,
	Turbo,
	Steering,
	Racing,
	ChangeP,
	ThewSquares,
	EnterName, 
	TheCredits,
	GameOver,
	Save,
	PickCar,
	CutsceneScreen
};


/// <summary>
/// Game class
/// </summary>
class Game
{
public:

	Game(); //constructor
	void init(); //initialise
	void run(); 
	void changeGameState(GameState gameState); //function to change the screen
	std::string getGarageTexture();
	sf::RenderWindow m_window;
	std::unique_ptr<Player> m_player; //player
	std::unique_ptr<ResourceManager> m_manager; //resource manager
	string nameDisplay();

	sf::Sound music;
	sf::Sound m_gameMusic; //game background audio

	int playerMoney();
	void chargePlayer(int amount);
	std::unique_ptr<PhysicsBalls>m_physicsBalls;
	std::unique_ptr<Background> m_background; //the background/ tiles
	std::unique_ptr<NightMode> m_nightMode;
	bool isInView(sf::Sprite sprite); //checks if a sprites in view
	std::string getBestLapTime(); 
	void resetMap();
	LevelData m_currentLevel;
	std::unique_ptr<TurboScreen>m_turboScreen; //turbo screen
	Xbox360Controller m_xbox; //xbox controller
	bool getPlayerPlace(); //find out if the player has won

private:
	void processInput();
	void update(sf::Time);
	void render();


	
	sf::Text m_name;

	sf::Font m_font;
	sf::Text m_text;


	GameState m_currentGameState = GameState::TheLicense; //current gamestate/screen
	//screens
	std::unique_ptr<playGame> m_mapSelect;
	std::unique_ptr<OptionsScreen> m_optionsScreen;
	std::unique_ptr<SoundScreen> m_soundScreen;
	std::unique_ptr<DisplayScreen> m_displayScreen;
	std::unique_ptr<GarageScreen> m_garageScreen;
	std::unique_ptr<MainMenu>m_MainMenu;
	std::unique_ptr<HelpScreen>m_helpScreen;
	std::unique_ptr<specs>m_specs;
	std::unique_ptr<Liscence>m_Liscence;
	std::unique_ptr<Splash>m_Splash;
	std::unique_ptr<BrakingScreen>m_brakingScreen;
	std::unique_ptr<SpeedScreen>m_speedScreen;
	std::unique_ptr<AccelerationScreen>m_accelerationScreen;
	std::unique_ptr<changeProfile> m_changeProfile;
	std::unique_ptr<Levels>m_level;
	std::unique_ptr<EnterNameScreen>m_enterName;
	std::unique_ptr<Credits>m_credits;
	std::unique_ptr<Cutscene>m_cutscene;
	std::unique_ptr<GameOverScreen>m_gameOverScreen;
	std::unique_ptr<SaveScreen>m_saveProfile;
	std::unique_ptr<ChooseCar>m_chooseCarScreen;
	/*Cars*/
	/**********************/
	std::unique_ptr<Car>m_car;
	std::unique_ptr<Car>m_aiCar;
	std::unique_ptr<Car>m_aiCarTwo;
	std::unique_ptr<Car>m_aiCarThree;
	std::unique_ptr<Ai>m_ai;
	std::unique_ptr<Ai>m_aiTwo;
	std::unique_ptr<Ai>m_aiThree;
	/**********************/

	//views
	sf::View m_view;
	sf::View m_view2;

	sf::Vector2f m_startPos;

	std::vector<sf::CircleShape> m_easyTrack;
	std::vector<sf::CircleShape> m_mediumTrack;
	std::vector<sf::CircleShape> m_hardTrack;



	LevelLoader m_levelLoader;
	bool hasName=false;
	sf::SoundBuffer m_buffer;
	sf::SoundBuffer m_buffer2; //buffers for music
	sf::Clock clock;
	sf::Time timeSinceLastUpdate;
	sf::Time timePerFrame;
	float totalTime;


	/******************************/

	sf::Image image;
	sf::Color color;
	sf::Sprite testSprite;
	sf::Color color2;

	/*******************************/

	sf::FloatRect rect;
	sf::Sprite sprBack;

	// Shader 
	sf::Sprite m_shaderSprite;
	sf::Shader m_smokeShader;

	bool levelReset = true;
};

#endif
