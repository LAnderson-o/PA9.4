#pragma once
#include "Header.h"
#include "Enemy.h"

class Enemies {
public:
	Enemies();
	~Enemies();

	void spawnEnemy(sf::RenderWindow* window);

	void despawnEnemy();
	//despawn condition and event (score etc)
	void update(sf::RenderWindow* window, sf::FloatRect bounds,
		float& dt, vector<Bullet*>& pBull,
		vector<Bullet*>& eBull, Vector2f pPos, int& score);
	//fires gun and moves enemies
	void render(sf::RenderWindow* window);

private:

	std::vector<Enemy*> enemyList;

	sf::Texture enemyTexture;


	int enemyid;

};