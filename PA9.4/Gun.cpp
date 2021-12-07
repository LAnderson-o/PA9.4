#include "Gun.h"



bool Gun::fireBullet(const sf::Vector2f& newPosition, const sf::Vector2i& newTarget, 
	vector<Bullet*> &pBull)
{
	clock.getElapsedTime();
	
	if (clock.getElapsedTime().asMilliseconds() > 300)
	{

		sf::Vector2f test = sf::Vector2f(newTarget) - newPosition;

		float n1;
		if (test.x < 0){
			n1 = atan(test.y / test.x) + 3.14159265;
		}
		else{
			n1 = atan(test.y / test.x);
		}
		float n2 = cos(n1);
		float n3 = sin(n1);
		test.x = n2;
		test.y = n3;

		Bullet* nBul = new Bullet(6, sf::Color::White, newPosition+sf::Vector2f(+17,0),
			test);
		pBull.push_back(nBul);
		
		clock.restart();
		return true;
	}
	else { return false; }
	
}
//
//Bullet* Gun::fireEBullet(const sf::Vector2f& newPosition, const sf::Vector2f& newTarget)
//{
//	//need to fix both of these to fire in certain direction
//	Bullet* nBul = new Bullet(6, sf::Color::White, newPosition);
//	return nBul;
//
//}

