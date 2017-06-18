#ifndef CUTSCENE
#define CUTSCENE

#include "Game.h"

class Game;

class Cutscene
{
public:
	Cutscene(Game &game);	//Constructor
	~Cutscene();			//Deconstructor

	void update(float dt);	// Update loop
	void render(sf::RenderWindow & window);	// Draw loop
	void load();	// Load in animation

private:
	Game *m_game;
	sfe::Movie m_cutscene;
	bool m_play;

	// Shader 
	sf::Sprite m_shaderSprite;
	sf::Shader m_waveShader;
};

#endif