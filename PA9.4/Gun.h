#pragma once


//container class, manages bullets, calcs speed, interact with power ups
//ought to be based on queue, should use linked list


#include "Bullet.h"
#include "Header.h"

//will delete

class Gun
{
public:
	Gun() = default;
	~Gun() = default;


	virtual Bullet* fireBullet(const sf::Vector2f& newPosition, int x, int y);
	//virtual Bullet* fireEBullet(const sf::Vector2f& newPosition, const sf::Vector2f& newTarget);
	//overridden for 

	

private:

	sf::Clock clock; //time since last fire, for pBull



};


