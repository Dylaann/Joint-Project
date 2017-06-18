#include"Slider.h"

/// <summary>
/// @mainpage Joint Project - 2D racing game.
/// @Author Dylan Murphy, Sean Regan, Micheal Bridgette, David O'Gorman
/// @Version 1.0
/// @brief A 2D racing game.
/// </summary>

//slider ui element
Slider::Slider(float x, float y, float &value, std::string s) :
	Widget()
{
	if (!m_font.loadFromFile("Fonts/AmericanCaptain.ttf"))
	{
		//error message
	}
	m_text.setFont(m_font);
	m_text.setString(s);
	m_text.setPosition(x-30, y-5);
	m_text.setColor(sf::Color::White);
	m_text.setCharacterSize(20);

	m_val = value;
	m_id = "slider";
	m_hasFocus = false;
	//outer rectangle
	m_rect.setPosition(x+(m_text.getGlobalBounds().width) , y);
	m_rect.setSize(sf::Vector2f(200.0f,20.0f));
	m_rect.setFillColor(sf::Color::Transparent);
	m_rect.setOutlineColor(sf::Color::Transparent);
	m_rect.setOutlineThickness(1);

	//inner rectangle, size dictacted by a value
	m_innerRect.setPosition(x+(m_text.getGlobalBounds().width )+10, y+5);
	m_innerRect.setSize(sf::Vector2f(m_rectX, m_rectY));
	m_innerRect.setFillColor(sf::Color::White);
	m_innerRect.setOutlineColor(sf::Color::Black);
	m_innerRect.setOutlineThickness(1);

	
}

//make slider get focus
void Slider::getFocus()
{
	m_hasFocus = true;
}
//make it lose focus
void Slider::loseFocus()
{
	m_hasFocus = false;
}

//check its current focus
bool Slider::checkFocus()
{
	return m_hasFocus;
}

//decrease the size of the rectangle
void Slider::decreaseValue()
{
	if (m_val > 0)
	{
		m_val--;
	}
}
//increase the size of the rectangle
void Slider::increaseValue()
{
	if (m_val < 100)
	{
		m_val++;
	}
}

//draw the components of the slider
void Slider::draw(sf::RenderWindow &window)
{
	window.draw(m_rect);
	window.draw(m_innerRect);
	window.draw(m_text);
	
}
//return value that represents the slider
int Slider::getValue()
{
	return m_val;
}

//update the slider component
void Slider::update()
{
	
	m_innerRect.setSize(sf::Vector2f(m_rectX*(m_val/100), m_rectY)); //chaneg the rectangles size based on the value


	if (m_hasFocus == true)
	{
		
		m_rect.setOutlineColor(sf::Color::Red);
	}
	else
	{
		m_rect.setOutlineColor(sf::Color::Transparent);
	}

}