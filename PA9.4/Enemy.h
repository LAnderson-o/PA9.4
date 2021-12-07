#pragma once
#include "Header.h"
#include "Guy.h"

class Enemy : public Guy {
public:

	Enemy(int newID, Vector2f& pos, Vector2f& nGoal);
	~Enemy() = default;

	void setID(int newID);
	
	virtual void movement(sf::RenderWindow* window, sf::FloatRect bounds, float &dt);
	
	
	int gX, gY;  //goal pos
	int mX, mY;


protected:
	int id;
	int speed;

	Vector2f goal;
	Vector2f mov;
	

};