#include "Player.h"

void Player::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{

		if (bounds.contains(sf::Vector2f(0, player.getPosition().y + 53))) {
			player.move(0, 3);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (bounds.contains(sf::Vector2f(0, player.getPosition().y + 20))) {
			player.move(0, -3);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (bounds.contains(sf::Vector2f(player.getPosition().x, 0))) {
			player.move(-3, 0);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (bounds.contains(sf::Vector2f(player.getPosition().x + 50, 0))) {
			player.move(3, 0);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Bullet* temp = player.firegun();
		if (temp != nullptr) {
			pBull.push_back(temp);
		}
	}

}
