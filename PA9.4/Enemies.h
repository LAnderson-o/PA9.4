#pragma once
#include "Header.h"
#include "Enemy.h"

class Enemies {
public:
	Enemies();
	void spawnEnemy();
private:
	sf::Texture enemyTexture;
	std::vector<Enemy> enemyList;
	int enemyid;
};