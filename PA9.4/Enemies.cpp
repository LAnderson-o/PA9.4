#include "Enemies.h"

Enemies::Enemies() {
	enemyTexture.loadFromFile("flytransparent.png");
	enemyid = 0;
}

Enemies::~Enemies()
{

	for (auto j : enemyList)
	{
		delete j;
	}

}

void Enemies::spawnEnemy(sf::RenderWindow* window) {

	Vector2f pos;
	pos.x = (rand() % window->getSize().x);
	pos.y = (rand() % window->getSize().y / 2);

	Vector2f goal;
	goal.x = (rand() % window->getSize().x);
	goal.y = (rand() % window->getSize().y);


	int dam = 1;
	Enemy* enemy1 = new Enemy(enemyid, pos, goal, dam);
	enemyid++;


	enemy1->setTexture(enemyTexture);
	enemyList.push_back(enemy1);

}

void Enemies::despawnEnemy() {

}

void Enemies::update(sf::RenderWindow* window, sf::FloatRect bounds, float& dt,
	vector<Bullet*>& pBull, vector<Bullet*>& eBull, Vector2f pPos, int& score)
{

	//loop through all enemies check if bullet intersects enemy or enemy intersects player
	for (int i = 0; i < enemyList.size(); ++i) {
		enemyList[i]->movement(window, bounds, dt);
		enemyList[i]->firegun(eBull, pPos);
		for (int j = 0; j < pBull.size(); ++j) {
			if (enemyList[i]->getGlobalBounds().intersects(pBull[j]->getGlobalBounds())) {
				score++;
				delete enemyList[i];
				enemyList.erase(enemyList.begin() + i);
				break;
			}
		}
	}

}

void Enemies::render(sf::RenderWindow* window) {
	for (auto j : enemyList) {
		window->draw(*j);
	}
}