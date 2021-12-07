#include "Enemies.h"

Enemies::Enemies(){
	enemyTexture.loadFromFile("flytransparent.png");
}

void Enemies::spawnEnemy() {
	Enemy enemy1(enemyid);
	enemyid++;
	int randy = (rand() % 320) + 320;
	int randx = rand() % 480;
	enemy1.setPosition(randx, randy);
	enemy1.setTexture(enemyTexture);
	enemyList.push_back(enemy1);
}


void Enemies::despawnEnemy() {
	
}


void Enemies::update() {
	//loop through all enemies check if bullet intersects enemy or enemy intersects player

}