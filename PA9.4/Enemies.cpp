#include "Enemies.h"

Enemies::Enemies(){
	enemyTexture.loadFromFile("flytransparent.png");

}

void Enemies::spawnEnemy() {
	Enemy enemy1(enemyid);
	enemyid++;
	
	enemy1.setPosition(100, 300);
	enemy1.setTexture(enemyTexture);
	enemyList.push_back(enemy1);
}


void Enemies::despawnEnemy() {
	

}


void Enemies::update() {
	//loop through all enemies check if bullet intersects enemy or enemy intersects player
	for (Enemy i : enemyList) {
		if (i.getPosition().x == i.gX && i.getPosition().y == i.gY) {
			//reached goal
			//assign new goal
			i.gX = rand() % 640;
			i.gY = rand() % 480;
		} else {
			float slope = i.gY - i.getPosition().y / i.gX - i.getPosition().x;
			i.mX = sin(slope);
			i.mY = cos(slope);
			i.move(i.mX, i.mY);

		}
		//calculate mx and my

	}
}