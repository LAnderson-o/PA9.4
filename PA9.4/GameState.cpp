#include "GameState.h"



GameState::GameState(sf::RenderWindow* nWindow)
{
	initalizeTextures();
	initalizePlayer();
	initalizeBackground();
	initalizeText();
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
		pBull[i]->move(pBull[i]->getVel().x * 200 * dt, pBull[i]->getVel().y * 200 * dt);
		//bounds despawning
		if (!bounds.contains(sf::Vector2f(pBull[i]->getPosition().x, pBull[i]->getPosition().y))) {
			delete pBull[i];
			pBull.erase(pBull.begin() + i);
			i--;
		
		}
	}

	for (int i = 0; i < eBull.size(); i++)
	{
		eBull[i]->move(eBull[i]->getVel().x * 200 * dt, eBull[i]->getVel().y * 200 * dt);
		//bounds despawning
		if (!bounds.contains(sf::Vector2f(eBull[i]->getPosition().x, eBull[i]->getPosition().y))) {
			delete eBull[i];
			eBull.erase(eBull.begin() + i);
			i--;
		}
		//player collision despawning
		else if (user.getGlobalBounds().intersects(eBull[i]->getGlobalBounds())) {
			user.setLife(user.getLife() - eBull[i]->getDam());//player damage

			delete eBull[i];
			eBull.erase(eBull.begin() + i);
			i--;
		}
	}

	//score
	string str = "Score: ";
	str += std::to_string(user.getScore());
	scoreText.setString(str);

	//life
	str = "Life: ";
	str += std::to_string(user.getLife());
	lifeText.setString(str);

	int randNum = rand() % 100;
	if (randNum == 35) {
		enemies.spawnEnemy(window);
	}
	enemies.update(window, bounds, dt, pBull, eBull, user.getPosition(), user.getScore());

}

void GameState::render()
{

	window->clear();

	window->draw(background);
	window->draw(scoreText);
	window->draw(lifeText);
	window->draw(user);
	enemies.render(window);

	//rendering bullets, should be own function
	for (int i = 0; i < pBull.size(); i++)
	{
		window->draw(*pBull[i]);
		
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
	user.setOrigin(user.getTextureRect().width / 2, user.getTextureRect().height / 2);
}


void GameState::initalizeEnemies() {

}

void GameState::initalizeText() {
	scoreFont.loadFromFile("fonts/comic.ttf");
	scoreText.setFont(scoreFont);
	scoreText.setPosition(10, 7);
	scoreText.setCharacterSize(18);

	lifeText.setFont(scoreFont);
	lifeText.setPosition(12, 30);
	lifeText.setCharacterSize(18);

	gameovertext.setFont(scoreFont);
	gameovertext.setPosition(bounds.width/2-gameovertext.getLocalBounds().width/2, bounds.height/2);

}

void GameState::gameOver() {
	
	for (int i = 0; i < 51; i++) {
		window->clear(sf::Color(255, 255, 255, i * 5));
		window->draw(gameovertext);
	}
	window->close();
}