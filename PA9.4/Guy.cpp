#include "Guy.h"

Bullet* Guy::firegun()
{
	return pGun.fireBullet(this->getPosition(), sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
	
}
