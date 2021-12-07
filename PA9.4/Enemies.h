#pragma once
#include "Header.h"
#include "Enemy.h"

class Enemies {
public:
	Enemies();
	void spawnEnemy();
	void despawnEnemy();
	void update();

	std::vector<Enemy> enemyList;
private:
	sf::Texture enemyTexture;
	int enemyid;
};