#include"Label.h"
/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

//label
Label::Label(std::string s,float x=0,float y=0):
	Widget()
{
	hasTexture = false; //standard label will have no texture
	m_id = "label";

	if (!m_font.loadFromFile("Fonts/AmericanCaptain.ttf"))
	{
		//error message
	}
	m_text.setFont(m_font);
	m_text.setString(s);
	m_text.setPosition(x, y);
	m_text.setColor(sf::Color::White);
	m_text.setCharacterSize(50);
	
}

//this is an alternative that we use for making ui icons
Label::Label(std::string s, float x, float y, std::string textureName):
	Widget()
{

	if (!m_texture.loadFromFile(textureName))
	{
	}
	m_sprite.setTexture(m_texture); //texture
	m_sprite.setPosition(x, y);
	m_sprite.setScale(0.5, 0.5);

	hasTexture = true;
	m_id = "label";
	if (!m_font.loadFromFile("Fonts/AmericanCaptain.ttf"))
	{
		//error message
	}
	m_text.setFont(m_font);
	m_text.setString(s);
	m_text.setPosition((x+m_sprite.getGlobalBounds().width), y);
	m_text.setColor(sf::Color::White);
	m_text.setCharacterSize(20);


	
}

Label::Label(std::string s, float x, float y, std::string textureName, std::string textureName2)
{
	if (!m_texture.loadFromFile(textureName))
	{
	}
	m_sprite.setTexture(m_texture); //texture
	m_sprite.setPosition(x, y+25);
	m_sprite.setScale(0.5, 0.5);




	has2Textures = true;
	m_id = "label";
	if (!m_font.loadFromFile("Fonts/AmericanCaptain.ttf"))
	{
		//error message
	}
	m_text.setFont(m_font);
	m_text.setString(s);
	m_text.setPosition((x + m_sprite.getGlobalBounds().width), y);
	m_text.setColor(sf::Color::White);
	m_text.setCharacterSize(100);

	if (!m_texture2.loadFromFile(textureName2))
	{
	}
	m_sprite2.setTexture(m_texture2); //texture
	m_sprite2.setPosition((m_text.getPosition().x + m_text.getGlobalBounds().width)+220, y+25);
	m_sprite2.setScale(-0.5, 0.5);
	//m_sprite2.setRotation(180);


}

//draw the label to the window
void Label::draw(sf::RenderWindow &window)
{
	window.draw(m_text);
	if (hasTexture == true) //draw the texture if there is one
	{
		window.draw(m_sprite);
	}
	if (has2Textures == true) //draw the texture if there is one
	{
		window.draw(m_sprite);
		window.draw(m_sprite2);
	}
}

//no current need to update the label
void Label::update()
{
}


//make the labels text underlined
void Label::setUnderLined()
{
	m_text.setStyle(sf::Text::Underlined);
}

//change the labels text
void Label::updateText(std::string s)
{
	m_text.setString(s);
}

//change the labels character size
void Label::changeTextSize(int size)
{
	m_text.setCharacterSize(size);
}
