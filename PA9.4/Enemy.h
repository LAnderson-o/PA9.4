#pragma once
#include "Header.h"
#include "Guy.h"

class Enemy : public Guy {
public:
	Enemy(int newID) {
		id = newID;
		goal.x = rand() % 320;
		goal.y = rand() % 480;
		setOrigin(getTextureRect().width/2, getTextureRect().height/2);

	};
	~Enemy() = default;

	void setID(int newID);
	
	virtual void movement();
	
	
	int id;
	int gX, gY;  //goal pos
	int mX, mY;


protected:
	int score;
	
	sf::Vector2f goal;
	sf::Vector2f mov;
	

};