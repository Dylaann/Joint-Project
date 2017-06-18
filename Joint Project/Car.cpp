#include "Car.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

double const DEG_TO_RAD = 3.14 / 180.0f;  //calculation for angle degrees to radians

//constructor for car object
Car::Car(Game & game, sf::Texture  & texture, sf::Vector2f const & pos):
	m_texture(&texture), m_position(pos), fader(0.15f, 0.15f), m_game(&game)
{

	// load car driving sound
	if (!m_buffer.loadFromFile("car driving.wav"))
	{
		std::cout << "Error loading car driving.wav" << std::endl;	//load the sound effect
	}
	//setup SF
	m_soundEffect.setBuffer(m_buffer);
	m_soundEffect.setLoop(true);
	m_soundEffect.setVolume(75);

	if (!m_Nshader.loadFromFile("Neon.frag", sf::Shader::Fragment))
	{
		std::cout << "shader failed to load" << std::endl;         //load shader
	}

	// Shader for when the car uses turbo
	shaderclock.restart();
	m_Nshader.setParameter("time", shaderclock.getElapsedTime().asSeconds());
	m_Nshader.setParameter("resolution", 50, 70); //set radius variable

	//setup car position and sprite
	m_position = sf::Vector2f(760, 1100);
	m_sprite.setTexture(*m_texture); //set texture

	m_position = sf::Vector2f(pos.x, pos.y);
	m_sprite.setPosition(m_position); //set pos

	//set origin to the front of the car
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 1.4, m_sprite.getTextureRect().height / 2.0);

	//init car variables
	m_speed = 0; 
	m_rotation = 0;
	m_acceleration = 2.25;
	m_deacceleration = 0.45;
	m_maxSpeed = 10;
	isMoving = false;

	// blank car sized texture to put over the car
	// It will have the shader applied to it
	sf::Texture& blankTexture = m_game->m_manager->m_textureHolder["blankCar"];
	blankTexture.setSmooth(true);

	// Skid mark particle effect
	sf::Texture& skidTexture = m_game->m_manager->m_textureHolder["skidMark"];
	system.setTexture(skidTexture);
	emitter.setEmissionRate(400);
	emitter.setParticleLifetime(sf::seconds(3));
	system.addEmitter(thor::refEmitter(emitter));
	system.addAffector(thor::AnimationAffector(fader));
	

	tempMaxSpeed = 4;
	m_turboAmount = 1;
	OriginalMaxSpeed = 10;
	m_steering = 2;

}

//in this update loop the movement formula is implemented and also the cars rotation is set
void Car::update(float dt)
{
	system.update(clock.restart());


	m_Nshader.setParameter("time", shaderclock.getElapsedTime().asSeconds());
	if (m_speed == 0.0f ||m_speed<0.9 &&m_speed>0.0)
	{
		isMoving = false;
		m_soundEffect.stop(); //no sound if not moving
	}
	else
	{
		isMoving = true;
		m_soundEffect.play(); //play when moving
	}
	

	if (isMoving == true)
	{
		m_sprite.setPosition((m_sprite.getPosition().x + cos(m_rotation*DEG_TO_RAD)*m_speed), (m_sprite.getPosition().y + sin(m_rotation*DEG_TO_RAD)*m_speed));   //car movement
		m_sprite.setRotation(m_rotation);  //car rotation 

		if (m_speed < 0.0&& m_speed>-0.99)
		{
			m_speed = 0;                  //just stop, as the car is already really slowing moving
		}
	}
	
}


void Car::aiUpdate(sf::Vector2f velocity)
{
	m_sprite.setPosition((m_sprite.getPosition().x + velocity.x), (m_sprite.getPosition().y + velocity.y));   //car movement
	m_sprite.setRotation(m_rotation);  //car rotation 
	
}


//draw the car to the screen
void Car::draw(sf::RenderWindow & window)
{
	window.draw(system);	// Particle effects

	window.draw(m_sprite);

	if (useTurbo == true)
	{
		window.draw(m_sprite, &m_Nshader);
	}
}

//when called the speed of the car increases
void Car::increaseSpeed()
{
	//for after turbo/ track changes to go back to normal speed
	if (m_speed > m_maxSpeed)
	{
		m_speed = m_maxSpeed; 
	}
	if (m_speed < m_maxSpeed)
	{
		m_speed += m_acceleration; //increase
	}
}

//when called the speed of the car decreases
void Car::decreaseSpeed()
{
	if (m_speed > -(m_maxSpeed))
	{
		m_speed -= m_deacceleration;
	}
}

void Car::increaseSpeed(float max)
{
	if (m_speed > max)
	{
		m_speed = max;
	}
	if (m_speed < max)
	{
		m_speed += m_acceleration; //increase
	}
}

void Car::decreaseSpeed(float max)
{
	if (m_speed > -(max))
	{
		m_speed -= m_deacceleration;
	}
}

//when called the rotation of the car increases
void Car::increaseRotation()
{
	m_rotation += m_steering;
	if (m_rotation == 360.0)
	{
		m_rotation = 0;
	}
}

//when called the rotation of the car decreases
void Car::decreaseRotation()
{
	m_rotation -= m_steering;
	if (m_rotation == 0.0)
	{
		m_rotation = 359.0;
	}
}

//when called the rotation of the car increases
void Car::increaseAiRotation()
{
	
	m_rotation = static_cast<int>((m_rotation) + 5) % 360;
}

//when called the rotation of the car decreases
void Car::decreaseAiRotation()
{
	m_rotation = static_cast<int>((m_rotation) - 5) % 360;
}

//function to rotate the texture to simulate a drift
void Car::drift(float rotation)
{
	m_sprite.rotate(rotation);

	emitter.setParticlePosition(sf::Vector2f(m_sprite.getPosition().x, m_sprite.getPosition().y));
	emitter.setParticleRotation(m_sprite.getRotation());
	system.update(clock.restart());
}

//set permenant rotation of the car
void Car::setRotation(float rotation)
{
	m_rotation = m_rotation + rotation;
	m_sprite.setRotation(m_rotation);
}

//parameter will be the max speed for duration of the turbo
void Car::turbo(float MaxturboSpeed)
{
	if (m_speed > MaxturboSpeed)
	{
		m_speed = m_maxSpeed;
	}
	if (m_speed < MaxturboSpeed)
	{
		m_speed += m_acceleration;
	}
	//bool that if true will draw the flame shader on the car 
	turboFlame = true;
}

//return the vector that represents the cars position on screen
sf::Vector2f Car::getPos()
{
	return m_sprite.getPosition();
}

//return the vector that represents the cars position on screen
float Car::getRot()
{
	return m_sprite.getRotation();
}

//slows down the car
void Car::slowDown()
{
	if(m_speed > 0.0)
	{
		m_speed -= m_deacceleration;
	} 
	else if (m_speed < 0.0)
	{
		m_speed += m_deacceleration;
	}
	
}

//return bool to check for movement
bool Car::isCarMoving()
{
	return isMoving;
}

//car breaks to slow the car down
void Car::breaks()
{
	m_speed *= 0.8;
	if (m_speed < 0.0&& m_speed>-0.8)
	{
		m_speed = 0;
	}
}

void Car::setAcceleration(float newValue)
{
	m_acceleration = newValue;
}

//sets max speed of the car
void Car::setMaxSpeed(float i)
{
	m_maxSpeed = i;
}

void Car::setSteering(float newValue)
{
	m_steering = newValue;
}

void Car::setTurbo(float newValue)
{
	m_turboAmount = newValue;
}

float Car::getMaxSpeed()
{
	return m_maxSpeed;
}

float Car::getSlowDownSpeed()
{
	return tempMaxSpeed;
}

float Car::getOriginalMaxSpeed()
{
	return OriginalMaxSpeed;
}

void Car::setOriginalMaxSpeed(float value)
{
	OriginalMaxSpeed = value;
}

void Car::useTurbos()
{
	if (m_turboAmount > 0)
	{
		m_turboAmount--;
	}
}

float Car::getTurbos()
{
	return m_turboAmount;
}



//Function for when car collides with brick wall
void Car::collision()
{
	m_speed *= 1.0;
	m_speed -= 4.0f;	
}

// sets the ai position on startup
void Car::setAiPosition(sf::Vector2f position)
{
	m_sprite.setPosition(position);
}

void Car::scaleAi()
{
	m_sprite.scale(2.25, 2.25);
}

void Car::resetPosition()
{
	m_sprite.setPosition(sf::Vector2f(760, 1100));
}

//gets the sprite
sf::Sprite Car::getSprite() const
{
	return m_sprite;
}

//for use when a new car is selected by the player
void Car::setTexture(sf::Texture & texture, float scaleX, float scaleY)
{
	m_texture = &texture; 
	m_sprite.setTexture(*m_texture);// apply new texture
	m_sprite.setPosition(m_position); //set pos
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 1.4, m_sprite.getTextureRect().height / 2.0);
	m_sprite.setScale(scaleX, scaleY); //scale the sprite
}

