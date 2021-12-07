#pragma once
#include "Header.h"
#include "Enemy.h"

class Enemies {
public:
	Enemies();
	void spawnEnemy(sf:: RenderWindow* window);
	void despawnEnemy();
	void update(sf::RenderWindow* window, sf::FloatRect bounds);

private:

	std::vector<Enemy*> enemyList;

	sf::Texture enemyTexture;
	
	
	int enemyid;
};