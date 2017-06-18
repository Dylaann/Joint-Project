#include "Cutscene.h"


// cutscene constructor
Cutscene::Cutscene(Game & game) :
	m_game(&game)
{
	load();	// load in animation

	// set up blank texture to go over animation
	sf::Texture& shaderTexture = m_game->m_manager->m_textureHolder["blankBackground"];
	m_shaderSprite.setTexture(shaderTexture);	// Set texture for the blank sprite
	
	// set up shaer
	if (!m_waveShader.loadFromFile("Shaders/wave.frag", sf::Shader::Fragment)) //Load shader
	{
		std::cout << "shader failed to load" << std::endl;	// Error message
	}
	m_waveShader.setParameter("time", 0.0f);
	m_waveShader.setParameter("mouse", 1280, 720);
	m_waveShader.setParameter("resolution", 1280.0f, 720.0f);
	m_shaderSprite.setPosition(0.0f, 0.0f);
}

//destructor
Cutscene::~Cutscene()
{
}

/// <summary>
/// update loop
/// </summary>
void Cutscene::update(float dt)
{
	// update the time parameter of the shader
	m_waveShader.setParameter("time", dt);

	// fit the animation and the shader to the screen
	m_cutscene.fit(sf::FloatRect(m_game->m_player->m_car.getPos().x - 639, m_game->m_player->m_car.getPos().y - 363, 1280, 720), true);
	m_shaderSprite.setPosition(m_game->m_player->m_car.getPos().x - 639, m_game->m_player->m_car.getPos().y - 363);
	
	// play animation
	m_play = true;
	if (m_play == true)
	{
		m_cutscene.play();
	}

	m_cutscene.update();	// update animation

	//if the animation is over change the gamestate to gameover
	if (m_cutscene.getStatus() == 0)
	{		
		m_play = true;
		m_game->changeGameState(GameState::GameOver);
	}
}

/// <summary>
/// Render loop
/// </summary>
void Cutscene::render(sf::RenderWindow & window)
{
	if (m_cutscene.getStatus() == 2)
	{
		window.draw(m_cutscene);	// Animation
		window.draw(m_shaderSprite, &m_waveShader);	// Shader drawn over the animation
	}
}

/// <summary>
/// load animation
/// </summary>
void Cutscene::load()
{
	// load in video fail
	if (!m_cutscene.openFromFile("cutscene.mp4"))
	{
		std::cout << "Cutscene animation not loaded" << std::endl;	// error message
	}
}
