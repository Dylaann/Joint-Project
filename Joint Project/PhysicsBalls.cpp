#include "PhysicsBalls.h"

/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>
/// Creates balls
/// </summary>
/// <param name="game"></param>
PhysicsBalls::PhysicsBalls(Game &game) : m_game(&game)
{

	sf::Texture& ballTex = m_game->m_manager->m_textureHolder["blueBall"];


	m_Position = sf::Vector2f(1600, 1100);

	for (int i = 0; i < 5; i++)
	{
		m_Position.x = m_Position.x + 300 * i;

		if (i == 1 || i == 3 || i == 5)
		{
			m_Position.y = 1000;
		}
		else
		{
			m_Position.y = 1100;
		}

		sf::Sprite m_tempBall;
		m_tempBall.setTexture(ballTex);
		m_tempBall.setPosition(m_Position);
		m_tempBall.setScale(0.5, 0.5);
		m_ballSprite.push_back(m_tempBall);
	}

}
/// <summary>
/// destructor
/// </summary>
PhysicsBalls::~PhysicsBalls()
{
}

/// <summary>
/// updates check for collisions
/// </summary>
void PhysicsBalls::update()
{
	collision();
}

/// <summary>
/// draws each ball
/// </summary>
/// <param name="window"></param>
void PhysicsBalls::render(sf::RenderWindow &window)
{
	for (int i = 0; i < 5; i++)
	{
		window.draw(m_ballSprite[i]);
	}
}

/// <summary>
/// Checks for collision with each ball
/// Slows player down
/// </summary>
void PhysicsBalls::collision()
{
	for (int i = 0; i < 5; i++)
	{
		if (m_ballSprite[i].getGlobalBounds().intersects(m_game->m_player->m_car.getSprite().getGlobalBounds()))
		{
			m_collision = true;
			if (m_collision)
			{
				m_game->m_player->m_car.setMaxSpeed(m_game->m_player->m_car.getMaxSpeed()/2.0f);
				/*m_ballSprite[i].setPosition((m_ballSprite[i].getPosition().x + cos(m_game->m_player->m_car.m_rotation * 3.14 / 180) * m_game->m_player->m_car.m_speed * 2),
					(m_ballSprite[i].getPosition().y + sin(m_game->m_player->m_car.m_rotation * 3.14 / 180) * m_game->m_player->m_car.m_speed * 2));*/

				
			}
		}
	}
}
