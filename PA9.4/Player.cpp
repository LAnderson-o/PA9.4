#include "Player.h"

void Player::update(sf::FloatRect& bounds, vector<Bullet*>& pBull, sf::RenderWindow* window, float& dt)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		firegun(window, pBull);

	}

	
	/////movement for player


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (bounds.contains(sf::Vector2f(0, this->getPosition().y+this->getGlobalBounds().height/2))) {
			this->move(0, speed*dt); //speed is pixels per second of speed
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (bounds.contains(sf::Vector2f(0, this->getPosition().y-this->getGlobalBounds().height / 2))) {
			this->move(0, -speed*dt);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (bounds.contains(sf::Vector2f(this->getPosition().x-this->getGlobalBounds().width/2, 0))) {
			this->move(-speed*dt, 0);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (bounds.contains(sf::Vector2f(this->getPosition().x + this->getGlobalBounds().width / 2, 0))) {
			this->move(speed*dt, 0);
		}
	}

	
	//rotation

	
	float n1;
	Vector2f rot = getPosition() - window->mapPixelToCoords(Mouse::getPosition(*window));

	if (rot.x < 0) {
		n1 = atan(rot.y / rot.x) + 3.14159265;
	}
	else {
		n1 = atan(rot.y / rot.x);
	}
	setRotation(n1*(float)(360/(2*3.14159625)) - 90);


}

bool Player::firegun(sf::RenderWindow* nWindow, vector<Bullet*>& pBull)
{
	return pGun.fireBullet(this->getPosition(), nWindow->mapPixelToCoords(Mouse::getPosition(*nWindow)), pBull);

}
