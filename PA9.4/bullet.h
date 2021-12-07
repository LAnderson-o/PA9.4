#pragma once
#include "Header.h"


class Bullet :
	public sf::CircleShape
{
public:
	Bullet(const double& newRadius, const sf::Color& newColor, const sf::Vector2f& newPosition)
		: sf::CircleShape(newRadius)
	{
		this->setFillColor(newColor);
		this->setPosition(newPosition);
	}

private:

};

