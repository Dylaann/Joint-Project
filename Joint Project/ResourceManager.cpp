#include "ResourceManager.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

ResourceManager::ResourceManager()
{
	// Textures
	m_textureHolder.acquire("garage", thor::Resources::fromFile<sf::Texture>("./all.png"));
	m_textureHolder.acquire("blueBackground", thor::Resources::fromFile<sf::Texture>("./backgroundBlue.png"));
	m_textureHolder.acquire("blankBackground", thor::Resources::fromFile<sf::Texture>("./blank.png"));
	m_textureHolder.acquire("blankCar", thor::Resources::fromFile<sf::Texture>("./blankNeon.png"));
	m_textureHolder.acquire("skidMark", thor::Resources::fromFile<sf::Texture>("./Skidmark2.png"));
	m_textureHolder.acquire("yellowCar", thor::Resources::fromFile<sf::Texture>("./lambo.png"));
	m_textureHolder.acquire("greenCar", thor::Resources::fromFile<sf::Texture>("./greenlambo.png"));
	m_textureHolder.acquire("blueCar", thor::Resources::fromFile<sf::Texture>("./bluelambo.png"));
	m_textureHolder.acquire("redCar", thor::Resources::fromFile<sf::Texture>("./redlambo.png"));
	m_textureHolder.acquire("greyCar", thor::Resources::fromFile<sf::Texture>("./greylambo.png"));
	m_textureHolder.acquire("whiteCar", thor::Resources::fromFile<sf::Texture>("./whitelambo.png"));
	m_textureHolder.acquire("policeCar", thor::Resources::fromFile<sf::Texture>("./police.png"));
	m_textureHolder.acquire("ambulance", thor::Resources::fromFile<sf::Texture>("./ambulance.png"));
	m_textureHolder.acquire("bus", thor::Resources::fromFile<sf::Texture>("./bus.png"));
	m_textureHolder.acquire("noise", thor::Resources::fromFile<sf::Texture>("./noisetexture.jpg"));
	m_textureHolder.acquire("mask", thor::Resources::fromFile<sf::Texture>("./mask.png"));
	m_textureHolder.acquire("blueBall", thor::Resources::fromFile<sf::Texture>("./blueBall.png"));
	m_textureHolder.acquire("raceBackground", thor::Resources::fromFile<sf::Texture>("./testTiles.png"));
	
	//Sounds
	m_textureHolder.acquire("dayLightMap", thor::Resources::fromFile<sf::Texture>("./Map1.PNG"));
	m_textureHolder.acquire("nightVisionMap", thor::Resources::fromFile<sf::Texture>("./Map2.png"));

	//Fonts
	m_fontHolder.acquire("americanCap", thor::Resources::fromFile<sf::Font>("Fonts/AmericanCaptain.ttf"));
	//m_fontHolder.acquire("Figurativative", thor::Resources::fromFile<sf::Font>("Figurativative.ttf"));

	m_songHolder.acquire("IntroSong", thor::Resources::fromFile<sf::SoundBuffer>("music.wav"));
	m_songHolder.acquire("GameSong", thor::Resources::fromFile<sf::SoundBuffer>("playing music.wav"));
}

ResourceManager::~ResourceManager()
{
}
