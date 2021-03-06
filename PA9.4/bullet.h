#pragma once
#include "Header.h"


class Bullet :
	public sf::CircleShape //to do: figure out how to apply texture
{
public:
	Bullet(const double& newRadius, const sf::Color& newColor,
		const sf::Vector2f& newPosition, const sf::Vector2f& newVel,
		int& damage)
		: sf::CircleShape(newRadius)
	{
		vel = newVel; //velocity vector, multiplied by dt and speed in gamestate
		this->setFillColor(newColor);
		this->setPosition(newPosition);
		this->setOrigin(getTextureRect().width / 2, getTextureRect().height / 2);
		dam = damage;
	}
	
	sf::Vector2f& getVel();
	int getDam();

private:
	sf::Vector2f vel;
	int dam;
};

