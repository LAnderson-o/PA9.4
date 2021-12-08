#include "Gun2.h"

bool Gun2::fireBullet(const sf::Vector2f& newPosition, const sf::Vector2f& newTarget, vector<Bullet*>& pBull)
{

	sf::Vector2f test = newTarget - newPosition;

	float n1;
	if (test.x < 0) {
		n1 = atan(test.y / test.x) + 3.14159265;
	}
	else {
		n1 = atan(test.y / test.x);
	}
	float n2 = cos(n1);
	float n3 = sin(n1);


	test.x = n2;
	test.y = n3;

	Bullet* nBul = new Bullet(6, sf::Color::White, newPosition + sf::Vector2f(-7, 0),
		test*speed, damage);
	pBull.push_back(nBul);

	float n1l = n1 + .08;
	float n1r = n1 - .08;

	n2 = cos(n1l);
	n3 = sin(n1l);

	test.x = n2;
	test.y = n3;
	/// second bullet

	Vector2f r;
	r.x = -test.y*10;
	r.y = test.x*10;

	nBul = new Bullet(6, sf::Color::White, newPosition + sf::Vector2f(-7, 0) + r,
		test*speed, damage);

	pBull.push_back(nBul);


	n2 = cos(n1r);
	n3 = sin(n1r);

	test.x = n2;
	test.y = n3;


	nBul = new Bullet(6, sf::Color::White, newPosition + sf::Vector2f(-7, 0) - r,
		test*speed, damage);

	pBull.push_back(nBul);




    return true;
}
