#include "Enemies.h"

Enemies::Enemies(){
	enemyTexture.loadFromFile("flytransparent.png");
}

void Enemies::spawnEnemy() {
	Enemy enemy1(enemyid);
	enemyid++;
	int randy = rand() % 320;
	int randx = rand() % 480;
	enemy1.setPosition(randx, randy);
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
		} else {

		}
		//calculate mx and my

	}
}