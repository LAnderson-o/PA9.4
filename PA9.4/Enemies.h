#pragma once
#include "Header.h"
#include "Enemy.h"

class Enemies {
public:
	Enemies();
	void spawnEnemy(sf:: RenderWindow* window);
	void despawnEnemy();
	void update(sf::RenderWindow* window, sf::FloatRect bounds);

	std::vector<Enemy> enemyList;
private:
	sf::Texture enemyTexture;
	int enemyid;
};