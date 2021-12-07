#pragma once
#include "Header.h"
#include "Guy.h"

class Enemy : public Guy {
public:

	Enemy(int newID, Vector2f& pos, Vector2f& nGoal);
	~Enemy() = default;

	void setID(int newID);
	
	virtual void movement(sf::RenderWindow* window, sf::FloatRect bounds, float &dt);
	
	
protected:
	int id;
	float speed;

	Vector2f goal;
	Vector2f mov;
	

};