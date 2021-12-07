#pragma once
#include "Header.h"
#include "Enemy.h"

class Enemies {
public:
	Enemies();
	void spawnEnemy(sf:: RenderWindow* window);
	void despawnEnemy();
	void despawn(sf::FloatRect bounds);
	void update(sf::RenderWindow* window);

	std::vector<Enemy> enemyList;
private:
	sf::Texture enemyTexture;
	int enemyid;
};