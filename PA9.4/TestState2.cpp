#include "TestState2.h"


TestState2::TestState2(sf::RenderWindow* nWindow)
{



	this->window = nWindow;


	initalizePlayer();
	shot = false;

	initalizeEnemy();
}

TestState2::~TestState2()
{
	delete testEnemy;

}


void TestState2::update(float& dt)
{

	if (shot == false)
	{
		Vector2f test2 = user->getPosition();
		testEnemy->firegun(eBull, test2);
		
		
	}
	//fire one bullet


	for (int i = 0; i < eBull.size(); i++)
	{
		shot = true;
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

			delete eBull[i];
			eBull.erase(eBull.begin() + i);
			i--;
			gameOver();

		}
	}


}

void TestState2::render()
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
	for (int i = 0; i < eBull.size(); i++)
	{
		window->draw(*eBull[i]);

	}


	window->display();
}

bool TestState2::gameOver()
{
	if (user->getLife() == 9 && eBull.size() == 0)
	{
		cout << "test passed" << endl;
	}
	else
	{
		cout << "test failed";
	}

	return false;
}

void TestState2::initalizeEnemy()
{
	Vector2f temp(window->getSize().x / 10, window->getSize().y / 10);
	int l = 3;

	enemyTexture.loadFromFile("flytransparent.png");

	testEnemy = new Enemy(window, temp, temp, l);
	testEnemy->setTexture(enemyTexture);












}
