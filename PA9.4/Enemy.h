#pragma once
#include "Header.h"
#include "Guy.h"

class Enemy : public Guy {
public:
	Enemy(int newID);
	void setID(int newID);
	int id;
	int gX, gY;
	int mX, mY;
protected:
	
};