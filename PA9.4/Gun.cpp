#include "Gun.h"



Bullet* Gun::fireBullet(const sf::Vector2f& newPosition, int x, int y)
{
	clock.getElapsedTime();

	if (clock.getElapsedTime().asMilliseconds() > 300)
	{
		Bullet* nBul = new Bullet(6, sf::Color::White, newPosition);
		clock.restart();
		return nBul;
	}
	else { return nullptr; }

}
//
//Bullet* Gun::fireEBullet(const sf::Vector2f& newPosition, const sf::Vector2f& newTarget)
//{
//	//need to fix both of these to fire in certain direction
//	Bullet* nBul = new Bullet(6, sf::Color::White, newPosition);
//	return nBul;
//
//}

