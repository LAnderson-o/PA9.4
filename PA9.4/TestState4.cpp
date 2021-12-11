#include "TestState4.h"


TestState4::TestState4(sf::RenderWindow* nWindow)
{



	this->window = nWindow;


	initalizePlayer();
	shot = false;

	
	initalizeEnemies();
}

TestState4::~TestState4()
{
	

}


void TestState4::update(float& dt)
{

	if (shot == false)
	{
	
		shot = true;
		Vector2f temp(window->getSize().x / 10, window->getSize().y / 10);
		Vector2f test2 = user->getPosition();
		enemies->spawnEnemy(temp, test2);
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
	if (score == 10)
	{
		user->upgrade();
	}

	enemies->update(bounds, dt, pBull, eBull, user->getPosition(), score);

	gameOver();

}

void TestState4::render()
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


void TestState4::initalizeEnemies()
{
	enemies = new EnemiesTest();
	enemies->setWin(window);

}



bool TestState4::gameOver()
{
	if ((enemies->getList()->at(0)->getPosition() - user->getPosition()).x > 0 &&
		(enemies->getList()->at(0)->getPosition() - user->getPosition()).x < 10 &&
		(enemies->getList()->at(0)->getPosition() - user->getPosition()).y > -100 && 
		(enemies->getList()->at(0)->getPosition() - user->getPosition()).y < 100)
	{
		cout << "test passed" << endl;
	}
	
	return false;
}

