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
		pBull[i]->move(pBull[i]->getVel().x *200*dt, pBull[i]->getVel().y *200*dt);
	}

	for (int i = 0; i < eBull.size(); i++)
	{
		eBull[i]->move(eBull[i]->getVel().x * 200 * dt, eBull[i]->getVel().y * 200 * dt);
	}



	int randNum = rand() % 100;
	if (randNum == 35) {
		enemies.spawnEnemy(window);
	}
	//despawnEnemey(ID);
	enemies.update(window, bounds, dt, pBull, eBull, user.getPosition());

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
		if (!background.getGlobalBounds().contains(sf::Vector2f(pBull[i]->getPosition().x, pBull[i]->getPosition().y))) {
			delete pBull[i];
			pBull.erase(pBull.begin() + i);
			break;
		}
		//if (user.getGlobalBounds().intersects(pBull[i]->getGlobalBounds())) { breaks the bullets
		//	// life--
		//	delete pBull[i];
		//	pBull.erase(pBull.begin() + i);
		//	break;
		//}
	}

	for (int i = 0; i < eBull.size(); i++)
	{
		window->draw(*eBull[i]);
	}


	window->display();
}


void GameState::initalizeBackground() {
	background.setTexture(backgroundTexture);
}


void GameState::initalizeTextures() {
    playerTexture.loadFromFile("frog1.1transparent.png");
	backgroundTexture.loadFromFile("Background.png");
}


void GameState::initalizePlayer() {
	//will change to pointer
    user.setPosition(400, 100);
    user.setTexture(playerTexture);
    user.setScale(sf::Vector2f(2.f, 2.f));
	user.setOrigin(user.getTextureRect().width/2, user.getTextureRect().height/2);
}


void GameState::initalizeEnemies() {

}