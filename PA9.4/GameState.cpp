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

void GameState::update(float& dt)
{
	user.update(bounds, pBull, window, dt);

	//update all bullets, will be its own function at some point
	for (int i = 0; i < pBull.size(); i++)
	{
		pBull[i]->move(pBull[i]->getVel().x *300*dt, pBull[i]->getVel().y *300*dt);
	}


	int randNum = rand() % 100;
	if (randNum == 35) {
		enemies.spawnEnemy(window);
	}
	//despawnEnemey(ID);
	enemies.update(window, bounds, dt);

}

void GameState::render()
{
	
	window->clear();

	window->draw(background);
	window->draw(user);
	enemies.render(window);
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
    playerTexture[0].loadFromFile("frog1.1transparent.png");
	playerTexture[1].loadFromFile("frog2transparent.png");
	playerTexture[2].loadFromFile("frog3transparent.png");
	backgroundTexture.loadFromFile("Background.png");
}


void GameState::initalizePlayer() {
	//will change to pointer
    user.setPosition(400, 100);
    user.setTexture(playerTexture[0]);
    user.setScale(sf::Vector2f(2.f, 2.f));
	user.setOrigin(user.getTextureRect().width/2, user.getTextureRect().height/2);
}


void GameState::initalizeEnemies() {

}