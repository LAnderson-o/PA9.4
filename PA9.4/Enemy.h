#pragma once
#include "Header.h"
#include "Guy.h"

class Enemy : public Guy {
public:
	Enemy(int newID);
	~Enemy() = default;

	void setID(int newID);
	
	virtual void movement();
	
	
	int id;
protected:
	int score;
	

};