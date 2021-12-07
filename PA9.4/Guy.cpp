#include "Guy.h"

bool Guy::firegun(sf::RenderWindow* nWindow, vector<Bullet*>& pBull)
{
	return pGun.fireBullet(this->getPosition(), nWindow->mapPixelToCoords(Mouse::getPosition(*nWindow)), pBull);
	
}
