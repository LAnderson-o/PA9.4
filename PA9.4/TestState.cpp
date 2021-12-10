#include "TestState.h"


TestState1::TestState1(sf::RenderWindow* nWindow)
{
	


	this->window = nWindow;

	
	initalizePlayer();
	shot = false;

	initalizeEnemy();
}

TestState1::~TestState1()
{
	delete testEnemy;

}


void TestState1::update(float& dt)
{

	if (shot == false)
	{
		user->firegun(testEnemy->getPosition(), pBull);
		shot = true;
	}
	//fire one bullet
	

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



	//same code from enemy manager class
	for (int j = 0; j < pBull.size(); ++j) {
		if (testEnemy->getGlobalBounds().intersects(pBull[j]->getGlobalBounds())) {

			delete pBull[j];
			pBull.erase(pBull.begin() + j);




			score++; //updates game score (might be hitting twice)
			delete testEnemy;
			testEnemy = nullptr;
			gameOver();
			
			break; //tinker with this alter

			

		}
	}



}

void TestState1::render()
{
	window->clear();



	window->draw(background);
	window->draw(scoreText);
	window->draw(lifeText);
	user->render();
	
	if (testEnemy != nullptr)
	{
		testEnemy->render();
	}
	
	//rendering bullets, should be own function
	for (int i = 0; i < pBull.size(); i++)
	{
		window->draw(*pBull[i]);

	}


	window->display();
}

bool TestState1::gameOver()
{
	if (testEnemy == nullptr)
	{
		cout << "test passed" << endl;
	}
	else
	{
		cout << "test failed";
	}

	return false;
}

void TestState1::initalizeEnemy()
{
	Vector2f temp(window->getSize().x, window->getSize().y / 3);
	int l = 3;

	enemyTexture.loadFromFile("flytransparent.png");

	testEnemy = new Enemy(window, temp, temp, l);
	testEnemy->setTexture(enemyTexture);
}
