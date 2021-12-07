#include "Guy.h"

Bullet* Guy::firegun(sf::RenderWindow* nWindow)
{
	return pGun.fireBullet(this->getPosition(), sf::Mouse::getPosition(*nWindow));
	
}
