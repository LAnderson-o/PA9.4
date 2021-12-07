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

void Enemies::despawn(sf::FloatRect bounds) {
	for (int i = 0; i < enemyList.size(); ++i) {
		if (!bounds.contains(enemyList[i].getPosition())) {
			std::vector<Enemy>::iterator it = enemyList.begin();
			std::advance(it, i);
			enemyList.erase(it);
		}
	}
}

void Enemies::update(sf::RenderWindow* window) {
	//loop through all enemies check if bullet intersects enemy or enemy intersects player
	for (Enemy i : enemyList) {
		if (i.getPosition().x == i.gX && i.getPosition().y == i.gY) {
			//reached goal
			//assign new goal
			i.gX = rand() % window->getSize().x;
			i.gY = rand() % window->getSize().y;
		} else {
			float slope = i.gY - i.getPosition().y / i.gX - i.getPosition().x;
			i.mX = sin(slope);
			i.mY = cos(slope);
			i.move(i.mX, i.mY);
		}
		//calculate mx and my

	}
}