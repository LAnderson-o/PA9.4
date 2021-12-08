#pragma once
#include "Gun.h"
class Gun2 :
    public Gun
{
public:
	Gun2() { speed = 1.1; damage = 2; }


	bool fireBullet(const sf::Vector2f& newPosition, const sf::Vector2f& newTarget,
		vector<Bullet*>& pBull);
private:

};

