
#include "TestState5.h"


TestState5::TestState5(sf::RenderWindow* nWindow)
{
	this->window = nWindow;

	initalizePlayer();
	shot = 0;

}

TestState5::~TestState5()
{


}


void TestState5::update(float& dt)
{

	if (shot < 3)
	{

		int t = pBull.size();


		Vector2f temp(window->getSize().x / 10, window->getSize().y / 10);
		Vector2f test2 = user->getPosition();
		user->firegun(temp, pBull);
		if (t > shot)
		{
			shot++;
		}
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

	
}



void TestState5::updateBul(float& dt)
{
	for (int i = 0; i < pBull.size(); i++)
	{
		pBull[i]->move(pBull[i]->getVel().x * 200 * dt, pBull[i]->getVel().y * 200 * dt);
		//bounds despawning
		if (!bounds.contains(sf::Vector2f(pBull[i]->getPosition().x, pBull[i]->getPosition().y))) {
			delete pBull[i];
			pBull.erase(pBull.begin() + i);
			i--;
			gameOver();

		}
	}




}


void TestState5::render()
{
	window->clear();



	window->draw(background);
	window->draw(scoreText);
	window->draw(lifeText);
	user->render();

	
	//rendering bullets, should be own function
	for (int i = 0; i < pBull.size(); i++)
	{
		window->draw(*pBull[i]);

	}


	window->display();
}

bool TestState5::gameOver()
{

	if (shot == 3 && pBull.size() == 0)
	{
		cout << "test passed" << endl;
	}

	return false;
}
