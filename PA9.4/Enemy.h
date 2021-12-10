#pragma once
#include "Header.h"
#include "Guy.h"


//allocated with enemy namger class
class Enemy : public Guy {
public:

	Enemy(sf::RenderWindow* nWindow, Vector2f& pos, Vector2f& nGoal, int& nLife);

	~Enemy() = default;


	virtual void movement(float &dt);
	//calcs move value and moves based on dt

	virtual bool firegun(vector<Bullet*>& eBull, Vector2f &target); //will need to change work with passed position 
	//firegun launches at player
	
protected:

	float speed; //speed it floats
	
	int shotTime; //randomly generated time to shooot a bullet

	Vector2f goal;//randomly generated goal to move to
	Vector2f mov; //small unit vector to move in, caed from goal and getPos
	Vector2f wMov; //small unit vector to move in, caed from goal and getPos
	
	Clock mClock; //for wiggle movement
};