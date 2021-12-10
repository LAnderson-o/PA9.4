#include "GameState.h"



GameState::GameState()
{
	initalizeTextures();

	initalizeBackground();
	initalizeText();
	bounds = background.getGlobalBounds();
	lost = false;

	
}

GameState::GameState(sf::RenderWindow* nWindow)
{
	initalizeTextures();
	
	initalizeBackground();
	initalizeText();
	bounds = background.getGlobalBounds();
	lost = false;
	start = false;
	this->window = nWindow;

	initalizeEnemies();
	initalizePlayer();
}

GameState::~GameState()
{
	//need to delete bullets 



	
}

void GameState::update(float& dt)
{
	user->update(bounds, pBull, dt);

	updateBul(dt);

	//update all bullets, will be its own function at some point
	//score
	string str = "Score: ";
	str += std::to_string(score);
	scoreText.setString(str);

	//life
	str = "Life: ";
	str += std::to_string(user->getLife());
	lifeText.setString(str);
	if (score == 10)
	{
		user->upgrade();
	}
	
	enemies.update(bounds, dt, pBull, eBull, user->getPosition(), score);

	
	

}


void GameState::updateBul(float& dt)
{
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
		else if (user->getGlobalBounds().intersects(eBull[i]->getGlobalBounds())) {
			user->setLife(user->getLife() - eBull[i]->getDam());//player damage
			gameOver();

			
			delete eBull[i];
			eBull.erase(eBull.begin() + i);
			i--;
		}
	}




}


void GameState::render()
{

	window->clear();



	window->draw(background);
	window->draw(scoreText);
	window->draw(lifeText);
	user->render();

	enemies.render();

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
	user = new Player(window);


	user->setPosition(window->getSize().x/2, window->getSize().y/2);
	user->setTexture(playerTexture);
	user->setScale(sf::Vector2f(2.f, 2.f));
	user->setOrigin(user->getTextureRect().width / 2, user->getTextureRect().height / 2);
}


void GameState::initalizeEnemies() {
	enemies.setWin(window);
}

void GameState::initalizeText() {
	scoreFont.loadFromFile("fonts/comic.ttf");
	scoreText.setFont(scoreFont);
	scoreText.setPosition(10, 7);
	scoreText.setCharacterSize(18);

	lifeText.setFont(scoreFont);
	lifeText.setPosition(12, 30);
	lifeText.setCharacterSize(18);


}

bool GameState::gameOver() {
	if (user->getLife() <= 0) {

		/*Clock gm;
		gm.getElapsedTime();*/


		gameovertext.setFont(scoreFont);
		gameovertext.setPosition(240, 240);
		gameovertext.setFillColor(sf::Color::White);
		gameovertext.setCharacterSize(32);
		gameovertext.setString("Game Over");
		scoreText.setPosition(320 - scoreText.getGlobalBounds().width / 2, 280);
		lost = true;
		//doesnt work too well
		while (window->isOpen())
		{

			window->clear(sf::Color::Black);
			window->draw(gameovertext);
			window->draw(scoreText);
			window->display();

		}
		
		 //could change condition later
		
	}
	return lost;
}
