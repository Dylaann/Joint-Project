#pragma once
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>
#include <Thor\Resources.hpp>
#include <SFML\Graphics.hpp>
#include<SFML\Audio.hpp>

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	thor::ResourceHolder<sf::Texture, std::string> m_textureHolder;	//Resource manager to hold textures
	thor::ResourceHolder<sf::Font, std::string> m_fontHolder;		//Resource manager to hold fonts
	thor::ResourceHolder<sf::SoundBuffer, std::string> m_songHolder;
};