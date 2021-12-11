#include "TestState3.h"


TestState3::TestState3(sf::RenderWindow* nWindow)
{



	this->window = nWindow;


	initalizePlayer();
	shot = false;

	
	initalizeEnemies();
}

TestState3::~TestState3()
{
	

}


void TestState3::update(float& dt)
{

	if (shot == false)
	{
	
		shot = true;
		Vector2f temp(window->getSize().x / 10, window->getSize().y / 10);
		Vector2f test2 = user->getPosition();
		enemies->spawnEnemy(temp, test2);
		user->firegun(temp, pBull);
	}
	//fire one bullet


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
	
	enemies->update(bounds, dt, pBull, eBull, user->getPosition(), score);
	gameOver();

}



void TestState3::updateBul(float& dt)
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
			

			delete eBull[i];
			eBull.erase(eBull.begin() + i);
			i--;
		}
	}




}


void TestState3::render()
{
	window->clear();



	window->draw(background);
	window->draw(scoreText);
	window->draw(lifeText);
	user->render();

	enemies->render();

	//rendering bullets, should be own function
	for (int i = 0; i < pBull.size(); i++)
	{
		window->draw(*pBull[i]);

	}


	window->display();
}

bool TestState3::gameOver()
{
	if (score != 0)
	{
		cout << "test passed" << endl;
	}
	
	return false;
}

void TestState3::initalizeEnemies()
{
	enemies = new EnemiesTest();
	enemies->setWin(window);

}

