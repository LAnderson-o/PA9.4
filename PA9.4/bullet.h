#pragma once
#include "Header.h"


class Bullet :
	public sf::CircleShape
{
public:
	Bullet(const double& newRadius, const sf::Color& newColor, 
		const sf::Vector2f& newPosition, const sf::Vector2f& newVel)
		: sf::CircleShape(newRadius)
	{
		vel = newVel;
		this->setFillColor(newColor);
		this->setPosition(newPosition);
	}
	
	sf::Vector2f& getVel();

private:

	float x; //x direction velocity
	float y; //y direction velocity
	sf::Vector2f vel;
};

