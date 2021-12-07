#include "Enemies.h"

Enemies::Enemies(){
	enemyTexture.loadFromFile("flytransparent.png");

}

void Enemies::spawnEnemy(sf::RenderWindow* window) {
	Enemy enemy1(enemyid);
	enemyid++;
	int randy = rand() % window->getSize().y/2;
	int randx = rand() % window->getSize().x;
	enemy1.setPosition(randx, randy);
	cout << enemy1.getPosition().x << " " << enemy1.getPosition().y << endl;
	enemy1.setTexture(enemyTexture);
	enemy1.gX = rand() % window->getSize().x;
	enemy1.gY = rand() % window->getSize().y;
	enemyList.push_back(enemy1);
}


void Enemies::despawnEnemy() {
	

}

void Enemies::update(sf::RenderWindow* window, sf::FloatRect bounds) {
	//loop through all enemies check if bullet intersects enemy or enemy intersects player
	for (int i = 0; i < enemyList.size(); ++i) {
		if (enemyList[i].getPosition().x == enemyList[i].gX && enemyList[i].getPosition().y == enemyList[i].gY) {
			//reached goal
			//assign new goal
			enemyList[i].gX = rand() % window->getSize().x;
			enemyList[i].gY = rand() % window->getSize().y;
		} else {
			float slope = enemyList[i].gY - enemyList[i].getPosition().y / enemyList[i].gX - enemyList[i].getPosition().x;
			enemyList[i].mX = sin(slope);
			enemyList[i].mY = cos(slope);
			enemyList[i].move(enemyList[i].mX, enemyList[i].mY);

		}
		//calculate mx and my

	}
}