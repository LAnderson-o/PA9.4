#pragma once
#include "Enemies.h"

class EnemiesTest : public Enemies
{
public:
	virtual void update(sf::FloatRect bounds,
		float& dt, vector<Bullet*>& pBull,
		vector<Bullet*>& eBull, Vector2f pPos, int& score);
	
	

private:



};

