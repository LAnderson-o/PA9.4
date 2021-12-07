#pragma once
#include "Header.h"
#include "Guy.h"

class Enemy : public Guy {
public:
	Enemy(int newID, Vector2f& pos, Vector2f& nGoal, Vector2f& nMov) {
		id = newID;
		goal = nGoal;
		mov = nMov;
		setPosition(pos);
	};
	~Enemy() = default;

	void setID(int newID);
	
	virtual void movement();
	
	
	int gX, gY;  //goal pos
	int mX, mY;


protected:
	int id;

	sf::Vector2f goal;
	sf::Vector2f mov;
	

};