#include "Guy.h"

Bullet* Guy::firegun()
{
	return pGun.fireBullet(this->getPosition(), sf::Mouse::getPosition());
	
}
