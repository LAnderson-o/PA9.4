#include "GameState.h"



GameState::GameState(sf::RenderWindow* nWindow)
{
	

	initalizeTextures();
	initalizePlayer();
	initalizeBackground();
	bounds = background.getGlobalBounds();
	this->window = nWindow;
}

GameState::~GameState()
{
}

void GameState::update()
{
	

	/////movement for player
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
	
	for (int i = 0; i < pBull.size(); i++)
	{
		pBull[i]->move(pBull[i]->getVel());
	}

}

void GameState::render()
{
	 
	window->clear();

	window->draw(background);
	window->draw(player);
	for (int i = 0; i < pBull.size(); i++)
	{
		window->draw(*pBull[i]);
	}

	window->display();
}


void GameState::initalizeBackground() {
	background.setTexture(backgroundTexture);
}


void GameState::initalizeTextures() {
    playerTexture[0].loadFromFile("frog1transparent.png");
	playerTexture[1].loadFromFile("frog2transparent.png");
	playerTexture[2].loadFromFile("frog3transparent.png");
	backgroundTexture.loadFromFile("Background.png");
}


void GameState::initalizePlayer() {
    player.setPosition(400, 100);
    player.setTexture(playerTexture[0]);
    player.setScale(sf::Vector2f(2.f, 2.f));
}
