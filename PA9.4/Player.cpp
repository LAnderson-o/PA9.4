#include "Player.h"

void Player::update(sf::FloatRect& bounds, vector<Bullet*>& pBull, sf::RenderWindow* window)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		firegun(window, pBull);

	}

	
	
	/////movement for player


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{

		if (bounds.contains(sf::Vector2f(0, this->getPosition().y + 53))) {
			this->move(0, 3);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (bounds.contains(sf::Vector2f(0, this->getPosition().y + 20))) {
			this->move(0, -3);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (bounds.contains(sf::Vector2f(this->getPosition().x, 0))) {
			this->move(-3, 0);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (bounds.contains(sf::Vector2f(this->getPosition().x + 50, 0))) {
			this->move(3, 0);
		}
	}

	

}
