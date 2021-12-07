#pragma once
#include "Header.h"


class Bullet :
	public sf::CircleShape //figure out how to apply texture
{
public:
	Bullet(const double& newRadius, const sf::Color& newColor, 
		const sf::Vector2f& newPosition, const sf::Vector2f& newVel)
		: sf::CircleShape(newRadius)
	{
		vel = newVel; //velocity vector, multiplied by dt in gamestate
		this->setFillColor(newColor);
		this->setPosition(newPosition);
	}
	
	sf::Vector2f& getVel();

private:
	sf::Vector2f vel;
};

