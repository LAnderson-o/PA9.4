#pragma once
#include "Header.h"
#include "Gun2.h"

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


	virtual bool firegun(sf::RenderWindow* nWindow, vector<Bullet*>& pBull) {
		return true;
	}; //will need to change work with passed position 




protected:
	sf::Clock clock; //foor calcing gun timing
	int life; //for life total
	Gun* pGun;
	int speed; //pixels per second to move
};




