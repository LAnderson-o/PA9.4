#pragma once
#include "Header.h"
#include "Enemy.h"

//enemy manager class
class Enemies {
public:
	Enemies();
	~Enemies();

	void setWin(sf::RenderWindow* nWindow);

	void spawnEnemy(Vector2f& pos, Vector2f goal);
	void despawnEnemy();
	//despawn condition and event (score etc)
	void update(sf::FloatRect bounds,
		float& dt, vector<Bullet*>& pBull,
		vector<Bullet*>& eBull, Vector2f pPos, int& score);
	//fires gun and moves enemies
	void render();
	//renders all enemies to screen
private:

	unsigned int spawnTime; //ms until next spawn
	Clock clock;


	sf::Texture enemyTexture;
	
	sf::RenderWindow* window; //window to interact with
	
	std::vector<Enemy*> enemyList;

};