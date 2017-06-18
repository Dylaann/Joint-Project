#include "LevelLoad.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

// find the font
void operator >> (const YAML::Node& FontNode, FontData& font)
{
	font.m_fileNameFont = FontNode["fontfile"].as<std::string>();
}

//find the car texture
void operator >> (const YAML::Node& lamboNode, LamboData& lambo)
{
	lambo.m_fileName = lamboNode["file"].as<std::string>();
}

//find the car texture
void operator >> (const YAML::Node& lamboNode, blueLamboData& lambo)
{
	lambo.m_fileName = lamboNode["file"].as<std::string>();
}

//find the tile map texture
void operator >> (const YAML::Node& tileNode, TileData& maptile)
{
	maptile.m_fileName = tileNode["file"].as<std::string>();
}

///file for the normal background
void operator >> (const YAML::Node& groundNode, GroundData& ground)
{
	ground.m_fileName = groundNode["groundfile"].as<std::string>();
}

//file for the sand background
void operator >> (const YAML::Node& sandNode, SandData& sand)
{
	sand.m_fileName = sandNode["sandfile"].as<std::string>();
}

void operator >> (const YAML::Node& garageNode, GarageData& garage)
{
	garage.m_fileName = garageNode["garagefile"].as<std::string>();
}

void operator >> (const YAML::Node& ballNode, BallData& ball)
{
	ball.m_fileName = ballNode["file"].as<std::string>();
}

/// <summary>
/// Loading data for the track
/// </summary>
/// <param name="trackNode"></param>
/// <param name="track"></param>
void operator >> (const YAML::Node& trackNode, TrackData& track)
{
	track.m_type = trackNode["type"].as<std::string>();				// Loading the type of node
	track.m_position.x = trackNode["position"]["x"].as<float>();	// Loading the nodes x position
	track.m_position.y = trackNode["position"]["y"].as<float>();	// Loading the nodes y position
	track.m_size = trackNode["size"].as<float>();					// Loading the size of the node
}

//video file for ceredits
void operator >> (const YAML::Node& creditsNode, CreditsData& credits)
{
	credits.m_fileName = creditsNode["file"].as<std::string>();
}

// video file for Lisence screen
void operator >> (const YAML::Node& lisenceNode, LisenceData& lisence)
{
	lisence.m_fileName = lisenceNode["file"].as<std::string>();
}

// video file for Splash screen
void operator >> (const YAML::Node& splashNode, SplashData& splash)
{
	splash.m_fileName = splashNode["file"].as<std::string>();
}

//all levelData
void operator >> (const YAML::Node& levelNode, LevelData& level)
{
	levelNode["bluelambo"] >> level.m_aiLambo;
	levelNode["lambo"] >> level.m_lambo;
	levelNode["font"] >> level.m_Font;
	levelNode["maptile"] >> level.m_Tiles;
	levelNode["ground"] >> level.m_ground;
	levelNode["sand"] >> level.m_sand;
	levelNode["garage"] >> level.m_garage;
	levelNode["credits"] >> level.m_credits;
	levelNode["lisence"] >> level.m_lisence;
	levelNode["splash"] >> level.m_splash;
	levelNode["ball"] >> level.m_ball;

	// For loop to load track data into m_track 
	const YAML::Node& mediumTrackNode = levelNode["trackMedium"].as<YAML::Node>();
	for (unsigned i = 0; i < mediumTrackNode.size(); ++i)
	{
		TrackData track;
		mediumTrackNode[i] >> track;
		level.m_mediumTrack.push_back(track);
	}

	// For loop to load track data into m_track 
	const YAML::Node& easyTrackNode = levelNode["trackEasy"].as<YAML::Node>();
	for (unsigned i = 0; i < easyTrackNode.size(); ++i)
	{
		TrackData track;
		easyTrackNode[i] >> track;
		level.m_easyTrack.push_back(track);
	}

	// For loop to load track data into m_track 
	const YAML::Node& hardTrackNode = levelNode["trackHard"].as<YAML::Node>();
	for (unsigned i = 0; i < hardTrackNode.size(); ++i)
	{
		TrackData track;
		hardTrackNode[i] >> track;
		level.m_hardTrack.push_back(track);
	}
}

LevelLoader::LevelLoader()
{
}

//Load in the yaml file
bool LevelLoader::load(LevelData& level)
{
	std::stringstream ss;
	//ss << resourcePath();
	ss << "level1.yaml";

	try
	{
		YAML::Node baseNode = YAML::LoadFile(ss.str());
		if (baseNode.IsNull())
		{
			std::string message("file: " + ss.str() + " not found");
			throw std::exception(message.c_str());
		}
		baseNode >> level;
	}
	catch (YAML::ParserException& e)
	{
		std::cout << e.what() << "\n";
		return false;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
		return false;
	}

	return true;
}
