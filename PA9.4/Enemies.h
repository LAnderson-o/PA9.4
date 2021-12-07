#pragma once
#include "Header.h"
#include "Enemy.h"

class Enemies {
public:
	Enemies();
	~Enemies() {}
	void spawnEnemy(sf::FloatRect& bounds,
		vector<Bullet*>& pBull, sf::RenderWindow* window, double& dt);
	void despawnEnemy();
	void update();

private:

	std::vector<Enemy*> enemyList;

	sf::Texture enemyTexture;
	
	
	int enemyid;
};