#include "Enemies.h"

Enemies::Enemies() 
{
	enemyTexture.loadFromFile("flytransparent.png");
	spawnTime = 3000;
}

Enemies::~Enemies()
{
	for (auto j : enemyList)
	{
		delete j;
	}
}

void Enemies::setWin(sf::RenderWindow* nWindow)
{
	window = nWindow;
}

void Enemies::spawnEnemy() {

	Vector2f pos;
	pos.x = (rand() % window->getSize().x);
	pos.y = (rand() % window->getSize().y / 2);

	Vector2f goal;
	goal.x = (rand() % window->getSize().x);
	goal.y = (rand() % window->getSize().y);


	int dam = 1;
	Enemy* enemy1 = new Enemy(window, pos, goal, dam);
	

	enemy1->setTexture(enemyTexture);
	enemyList.push_back(enemy1);

}

void Enemies::despawnEnemy() {

}

void Enemies::update(sf::FloatRect bounds, float& dt,
	vector<Bullet*>& pBull, vector<Bullet*>& eBull, Vector2f pPos, int& score)
{
	//spawn enemy condition
	if (clock.getElapsedTime().asMilliseconds() > rand() % spawnTime)
	{
		clock.restart();
		if (spawnTime > 1000)
		{
			spawnTime += -50;
		}
		spawnEnemy();
	}



	//loop through all enemies check if bullet intersects enemy or enemy intersects player
	for (int i = 0; i < enemyList.size(); ++i) {
		enemyList[i]->movement(dt);
		enemyList[i]->firegun(eBull, pPos);
		for (int j = 0; j < pBull.size(); ++j) {
			if (enemyList[i]->getGlobalBounds().intersects(pBull[j]->getGlobalBounds())) {
				score++; //updates game score
				delete enemyList[i];
				enemyList.erase(enemyList.begin() + i);
				break; //tinker with this alter
			}
		}
	}

}

void Enemies::render() {
	for (auto j : enemyList) {

		j->render();
	}
}