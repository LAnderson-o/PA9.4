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
	player.update();

	
	for (int i = 0; i < pBull.size(); i++)
	{
		pBull[i]->move(0, -4);
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
