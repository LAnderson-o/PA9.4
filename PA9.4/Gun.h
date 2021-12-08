#pragma once


//container class, manages bullets, calcs speed, interact with power ups
//ought to be based on queue, should use linked list


#include "Bullet.h"
#include "Header.h"


class Gun
{
public:
	Gun() { speed = 1; damage = 1; }
	~Gun() = default;
	
	virtual bool fireBullet(const sf::Vector2f& newPosition, const sf::Vector2f& newTarget,
		 vector<Bullet*> &pBull);
	//virtual Bullet* fireEBullet(const sf::Vector2f& newPosition, const sf::Vector2f& newTarget);
	//overridden for 
	

	
protected:
	float speed;
	int damage;


};


