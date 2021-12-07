#include "Gun.h"



Bullet* Gun::fireBullet(sf::Vector2f& newPosition, sf::Vector2i& newTarget)
{
	clock.getElapsedTime();
	
	if (clock.getElapsedTime().asMilliseconds() > 300)
	{

		sf::Vector2f(newTarget);



		int nx = newTarget.x - newPosition.x;
		int ny = newTarget.y - newPosition.y;
		
		
		float mag = sqrt(nx ^ 2 + ny ^ 2);

		Bullet* nBul = new Bullet(6, sf::Color::White, newPosition+sf::Vector2f(+17,0),
			(float)nx/mag, (float)ny/mag);
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

