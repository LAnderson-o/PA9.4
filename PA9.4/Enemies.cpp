#include "Enemies.h"

Enemies::Enemies(){
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

	

	Enemy* enemy1 = new Enemy(enemyid, pos, goal);
	enemyid++;


	enemy1->setTexture(enemyTexture);
	enemyList.push_back(enemy1);

}

void Enemies::despawnEnemy() {
	
}

void Enemies::update(sf::RenderWindow* window, sf::FloatRect bounds, float& dt) {
	
	//loop through all enemies check if bullet intersects enemy or enemy intersects player
	for (int i = 0; i < enemyList.size(); ++i) {
		if (enemyList[i]->getPosition().x == enemyList[i]->gX && enemyList[i]->getPosition().y == enemyList[i]->gY) {
			//reached goal
			//assign new goal
			enemyList[i]->gX = rand() % window->getSize().x;
			enemyList[i]->gY = rand() % window->getSize().y;
		} else if (!bounds.contains(enemyList[i]->getPosition())) {
			enemyList[i]->gX = rand() % window->getSize().x;
			enemyList[i]->gY = rand() % window->getSize().y;
		} else {
			float slope = enemyList[i]->gY - enemyList[i]->getPosition().y / enemyList[i]->gX - enemyList[i]->getPosition().x;
			/*enemyList[i].mX = sin(slope);
			enemyList[i].mY = cos(slope);
			cout << sin(slope) << " " << cos(slope) << endl;*/
			enemyList[i]->move(sin(slope), cos(slope));
		}
		//calculate mx and my

		//calculate mx and my

		//calculate mx and my

		//calculate mx and my

	}
}

void Enemies::render(sf::RenderWindow* window) {
	for (auto j : enemyList) {
		window->draw(*j);
	}
}