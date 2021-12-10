#include "TestState.h"


TestState::TestState(sf::RenderWindow* nWindow)
{
	initalizeTextures();

	initalizeBackground();
	initalizeText();
	bounds = background.getGlobalBounds();
	lost = false;
	this->window = nWindow;
	
	Vector2f temp(window->getSize().x / 2, window->getSize().y);
	int l = 3;

	testEnemy = new Enemy(window, temp, temp, l);
	
	initalizePlayer();
	shot = false;
}

TestState::~TestState()
{
}

void TestState::update(float& dt)
{
	if (shot == false)
	{
		user->firegun(testEnemy->getPosition(), pBull);
		shot = true;
	}
	//fire one bullet
	
	//same code from enemy manager class
	for (int j = 0; j < pBull.size(); ++j) {
		if (testEnemy->getGlobalBounds().intersects(pBull[j]->getGlobalBounds())) {

			delete pBull[j];
			pBull.erase(pBull.begin() + j);



			score++; //updates game score (might be hitting twice)
			delete testEnemy;
			testEnemy = nullptr;
			break; //tinker with this alter

			

		}
	}



}

void TestState::render()
{
	window->clear();



	window->draw(background);
	window->draw(scoreText);
	window->draw(lifeText);
	user->render();

	testEnemy->render();

	//rendering bullets, should be own function
	for (int i = 0; i < pBull.size(); i++)
	{
		window->draw(*pBull[i]);

	}

}

bool TestState::gameOver()
{
	return false;
}
