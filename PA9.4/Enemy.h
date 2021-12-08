#pragma once
#include "Header.h"
#include "Guy.h"

class Enemy : public Guy {
public:

	Enemy(int newID, Vector2f& pos, Vector2f& nGoal, int& nLife);

	~Enemy() = default;

	void setID(int newID);
	//for setting enemy id

	virtual void movement(sf::RenderWindow* window, sf::FloatRect bounds, float &dt);
	//calcs move value and moves based on dt

	virtual bool firegun(vector<Bullet*>& eBull, Vector2f &target); //will need to change work with passed position 
	//firegun launches at player
	
protected:
	int id; 
	float speed; //speed it floats
	
	int shotTime; //randomly generated time to shooot a bullet

	Vector2f goal;//randomly generated goal to move to
	Vector2f mov; //small unit vector to move in, caed from goal and getPos
	Vector2f wMov; //small unit vector to move in, caed from goal and getPos
	
	Clock mClock; //for wiggle movement
};