#pragma once
#ifndef PLAYER
#define PLAYER
#include "game.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include "Car.h"
#include "XBOX360CONTROLLER.h"
#include "background.h"

/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>
class Game;

class Player
{
public:
	Player(float carX, float carY, sf::Texture &carTexture, sf::RenderWindow &window, Game &game);
	
	~Player();
	void load(std::string name);
	void save(std::string replace);
	void cost(int amount);
	void earned(int amount);
	int getMoney();
	void newPlayer(std::string name);
	void setHighScore(int min, int sec);
	void setName(std::string name);
	int getMinHighScore();
	int getSecHighScore(); 
	std::string getName();
	void update(float dt, sf::View &view);
	void draw(sf::RenderWindow & window);
	Car m_car; //the players car

private:
	std::string filename;
	std::ifstream fileInput;

	std::ofstream fileOutput;
	std::stringstream fileStream;
	std::string fileLine;
	int m_money;
	int m_secHighScore;
	int m_minHighScore;
	std::string m_name;
	Xbox360Controller m_xbox;
	sf::RenderWindow *m_window;
	bool carTurning = false;
	bool carTurningLeft = false;
	bool breaks = false;
	bool carMoving = false;

	float currentDrift = 0.0f;
	sf::Clock m_turboTimer;
	Game *m_game;

	const int NUM_OF_PLAYERS = 10;				// Variable for the number of players in the text file 

	std::string strTemp;				// String to hold the data of each player before putting it in the output file
	int currentSkid = 1;
	sf::Vector2f m_position;

};

#endif