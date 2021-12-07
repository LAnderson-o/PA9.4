#pragma once
#include "Header.h"
#include "Gun.h"

	//plant to inherat from this to create "player" and "enemy" class 
	//will contain life, points on death, could have other stuff

class Guy :
	public sf::Sprite
{
public:

	//Guy(const double& newRadius, const sf::Vector2f& newPosition) : sf::Sprite(newRadius)
	//{
	//	//will update to set passed texture
	//	
	//	this->setPosition(newPosition);
	//}
	Guy() = default;
	~Guy() = default;


	//??any point to inheratance when we dont use "player guns"?
	virtual Bullet* firegun(sf::RenderWindow* nWindow); //will need to change work with passed position 



protected:
	sf::Clock clock;

	Gun pGun;
};




