#include "Player.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

Player::Player(float carX, float carY, sf::Texture &carTexture, sf::RenderWindow &window, Game &game):
	m_car(game, carTexture, sf::Vector2f(carX,carY)),
	m_window(&window),
	m_game(&game)
{
	m_money = 10000;
	m_secHighScore = 1000;
	m_minHighScore = 1000;
	m_name = "Guest";
	filename = "players.txt";


	
}


Player::~Player()
{
}

/// <summary>
/// Method to load a certain file from the player text file
/// </summary>
/// <param name="name"></param>
void Player::load(std::string name)
{
	fileInput.open(filename);					// Open the input file

	while (fileInput.is_open())					// While the input file is open
	{
		fileInput >> fileLine;					// Get the next line
		if (fileLine == name)					// If this is the players name
		{
			m_name = name;						// Give the player this name

			fileInput >> fileLine;				// Get the next line 
			m_money = stoi(fileLine);			// Assign the value to the player's money

			fileInput >> fileLine;				// Get the next line
			m_secHighScore = stoi(fileLine);	// Assign the value to the player's seconds portion of their highscore

			fileInput >> fileLine;				// Get the next line
			m_minHighScore = stoi(fileLine);	// Assign the value to the player's minutes portion of their highscore

			fileInput.close();					// Close the input file
		}
		else									// If this is not the player
		{

			fileInput >> fileLine;				// Get the next line (don't do anything)
			fileInput >> fileLine;				// Get the next line (don't do anything)
			fileInput >> fileLine;				// Get the next line (don't do anything)
		}

		if (fileInput.eof())					// If at the end of the file
		{
			fileInput.close();					// Close the input file
		}

	}
	
}

/// <summary>
/// Save current players data to a text file
/// </summary>
/// <param name="replace"></param>
void Player::save(std::string replace)
{


	fileInput.open(filename);			// Old file to be copied
	fileOutput.open("temp.txt");		// Temp file to work as middle man

	
	for (int i = 0; i < NUM_OF_PLAYERS; i++)
	{
		fileInput >> fileLine;			// Get next line (name)

		if (fileLine == replace)		// If the name is the same as the one we are looking to overwrite
		{
			strTemp += m_name.c_str();	// Add name
			strTemp += "\n";			// Add a new line

			fileInput >> fileLine;		// Go to next line (don't do anything with it)
			strTemp += std::to_string(m_money);		// Add current money
			strTemp += "\n";			// Add a new line

			fileInput >> fileLine;		// Go to next line (don't do anything with it)
			strTemp += std::to_string(m_secHighScore);	// Add seconds portion of highscore
			strTemp += "\n";			// Add a new line

			fileInput >> fileLine;		// Go to next line (don't do anything with it)
			strTemp += std::to_string(m_minHighScore);	// Add minutes portion of highscore
			strTemp += "\n";			// Add a new line
		}
		else							// If it not the player we are looking for leave it unchanged
		{

			strTemp += fileLine;		// Add the name of the player to the temp string
			strTemp += "\n";			// Add a new line

			fileInput >> fileLine;		// Get the next line and assign it to fileLine
			strTemp += fileLine;		// Add the amount of money to the temp string
			strTemp += "\n";			// Add a new line

			fileInput >> fileLine;		// Get the next line and assign it to fileLine
			strTemp += fileLine;		// Add the seconds portion of highscore
			strTemp += "\n";			// Add a new line
			
			strTemp += fileLine;		// Get the next line and assign it to fileLine
			fileInput >> fileLine;		// Add the minutes portion of highscore
			strTemp += "\n";			// Add a new line

		}

		fileOutput << strTemp;			// Assign everything in strTemp to the output file
		strTemp = "";					// Clear strTemp

	
	}
	
	fileInput.close();			// Close the input file
	fileOutput.close();			// Close the output file


	// Writing the temp file to the player file

	fileInput.open("temp.txt");		// Open temp file to read from
	fileOutput.open(filename);		// Open player file to write to

	for (int i = 0; i < NUM_OF_PLAYERS; i++)
	{
		// Player Name
		fileInput >> fileLine;		// Read a line
		strTemp += fileLine;		// Assign it to a temporary string
		strTemp += "\n";			// Go to the next line

		// Money
		fileInput >> fileLine;		// Get the next line
		strTemp += fileLine;		// Assign it to a temporary string
		strTemp += "\n";			// Go to the next line

		// Highscore minutes
		fileInput >> fileLine;		// Get the next line
		strTemp += fileLine;		// Assign it to a temporary string
		strTemp += "\n";			// Go to the next line

		// Highscore seconds
		fileInput >> fileLine;		// Get the next line
		strTemp += fileLine;		// Assign it to a temporary string
		strTemp += "\n";			// Go to the next line 


		fileOutput << strTemp;		// Assign everything that is in the temp string to the player file
		strTemp = "";				// Clear temp string
	}

		
	fileInput.close();		// Close the temp file and stop reading
	fileOutput.close();		// Close the player file and stop writing

	
}

/// <summary>
/// Method to decrease the amount of money the player has
/// </summary>
/// <param name="amount"></param>
void Player::cost(int amount)
{
	m_money -= amount;
}

/// <summary>
/// Method to increase the amount of money the player has
/// </summary>
/// <param name="amount"></param>
void Player::earned(int amount)
{
	m_money += amount;
}

/// <summary>
/// Method to get the current amount of money a player has
/// </summary>
/// <returns></returns>
int Player::getMoney()
{
	return m_money;
}

/// <summary>
/// Method to set the players highscore
/// </summary>
/// <param name="min"></param>
/// <param name="sec"></param>
void Player::setHighScore(int min, int sec)
{
	m_minHighScore = min;
	m_secHighScore = sec;
}

/// <summary>
/// Method to change the players name
/// </summary>
/// <param name="name"></param>
void Player::setName(std::string name)
{
	m_name = name;
}

/// <summary>
/// Method to create a new player
/// </summary>
/// <param name="name"></param>
void Player::newPlayer(std::string name)
{
	m_name = name;
	m_money = 1000;
	m_secHighScore = 1000;
	m_minHighScore = 1000;
}

/// <summary>
/// Method to return the name of the player
/// </summary>
/// <returns></returns>
std::string Player::getName()
{
	return m_name;
}

//where all the actions of the car are handled
// updated to handle drift
void Player::update(float dt, sf::View &view)
{
	carTurning = false;
	carTurningLeft = false;
	breaks = false;
	carMoving = false;

	view.setCenter(m_car.getPos()); //follow the player car
	m_window->setView(view);
	m_car.update(dt);

	m_xbox.update();

	if (m_xbox.m_currentState.RTtrigger<-10.0)
	{
		m_car.increaseSpeed();
		carMoving = true;
	}

	else if (m_xbox.m_currentState.RTtrigger < 0.0&& m_xbox.m_currentState.RTtrigger > -10.0)
	{
		m_car.slowDown();
	}

	if (m_xbox.m_currentState.LTtrigger>10.0)
	{
		m_car.decreaseSpeed();
	}
	if (m_car.isCarMoving() == true)
	{
		if (m_xbox.m_currentState.LeftThumbStick.x > 75)
		{
			carTurningLeft = false;
			m_car.increaseRotation();
			carTurning = true;
		}
		if (m_xbox.m_currentState.LeftThumbStick.x < -75)
		{
			carTurning = false;
			m_car.decreaseRotation();
			carTurningLeft = true;
		}
	}
	
	if (m_xbox.m_currentState.A)
	{
		m_car.breaks();
		breaks = true;
	}
	
	if (breaks && carMoving && carTurning)
	{
		if (currentDrift == 45)
		{
			currentDrift = 44.5;
		}

		if (currentDrift < 0)
		{
			currentDrift += 0.5;
			m_car.drift(currentDrift);
		}

		if(currentDrift < 45 && currentDrift >= 0)
		{
			currentDrift += 0.5;
			m_car.drift(currentDrift);
		}

	}
	else if (breaks && carMoving && carTurningLeft)
	{
		if (currentDrift == -45)
		{
			currentDrift = -44.5;
		}

		if (currentDrift > 0)
		{
			currentDrift -= 0.5;
			m_car.drift(currentDrift);
		}

		if(currentDrift > -45 && currentDrift <= 0)
		{
			currentDrift -= 0.5;
			m_car.drift(currentDrift);
		}

	}
	else if (carMoving)
	{
		if (currentDrift > -47 && currentDrift < 0)
		{
			currentDrift += 1;
			m_car.drift(currentDrift);
		}

		if (currentDrift < 47 && currentDrift > 0)
		{
			currentDrift -= 1;
			m_car.drift(currentDrift);
		}

	}
	else 
	{
		m_car.setRotation(currentDrift);
		currentDrift = 0;
	}



	//press Y to use the cars turbo
	if (m_xbox.m_currentState.Y && !m_xbox.m_previousState.Y&&m_car.useTurbo == false && m_car.getTurbos()!=0)
	{
		m_car.useTurbo = true;
		m_car.useTurbos();
		m_game->m_background->activateTheShader(); //activate blur effect
		m_turboTimer.restart(); //restart timer
	}


	if (m_car.useTurbo == true)
	{
		if (m_turboTimer.getElapsedTime().asSeconds() > 2) //turbo for limited time
		{

			m_car.useTurbo = false;
			m_game->m_background->activateTheShader(); //reset blur
		}
	}




}

// Draw loop
void Player::draw(sf::RenderWindow & window)
{
	m_car.draw(window);
}



/// <summary>
///  Method to return the minutes portion of the players highscore
/// </summary>
/// <returns></returns>
int Player::getMinHighScore()
{
	return m_minHighScore;
}

/// <summary>
/// Method to return the seconds portion of the players highscore
/// </summary>
/// <returns></returns>
int Player::getSecHighScore()
{
	return m_secHighScore;
}