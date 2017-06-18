#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML\Graphics.hpp>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include "yaml-cpp/yaml.h"
#include "ResourcePath.hpp"

/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>
/// loads information from yaml file
/// images, music and font files
///<summary>
struct FontData
{
	std::string m_fileNameFont;
};

struct LamboData
{
	std::string m_fileName;
};

struct blueLamboData
{
	std::string m_fileName;
};

struct TileData
{
	std::string m_fileName;
};

struct GroundData
{
	std::string m_fileName;
};

struct SandData
{
	std::string m_fileName;
};

struct TrackData
{
	std::string m_type;
	sf::Vector2f m_position;
	float m_size;
};

struct GarageData
{
	std::string m_fileName;
};

struct CreditsData
{
	std::string m_fileName;
};

struct LisenceData
{
	std::string m_fileName;
};

struct SplashData
{
	std::string m_fileName;
};

struct BallData
{
	std::string m_fileName;
};


//contains all the levels data
struct LevelData
{
	LamboData m_lambo;
	FontData m_Font;
	TileData m_Tiles;
	GroundData m_ground;
	SandData m_sand;
	blueLamboData m_aiLambo;
	GarageData m_garage;
	std::vector<TrackData> m_mediumTrack;
	std::vector<TrackData> m_easyTrack;
	std::vector<TrackData> m_hardTrack;
	CreditsData m_credits;
	LisenceData m_lisence;
	SplashData m_splash;
	BallData m_ball;
};


//class to load in the level details
class LevelLoader
{
public:
	LevelLoader();

	static bool load(LevelData& level);
};
