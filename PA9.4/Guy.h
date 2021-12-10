#pragma once
#include "Header.h"
#include "Gun2.h"

//plant to inherat from this to create "player" and "enemy" class 
//will contain life, points on death, could have other stuff

class Guy :
	public sf::Sprite
{
public:

	//Guy(const double& newRadius, const sf::Vector2f& newPosition) : sf::Sprite(newRadius)
	//{
	//	//will update to set passed texture
	//	
	//	this->setPosition(newPosition);
	//}
	Guy() = default;
	~Guy() = default;


	virtual bool firegun(vector<Bullet*>& pBull) {
		return false;
	}; //will need to change work with passed position 

	void setLife(int newLife);
	int getLife();

	void setScore(int newScore);
	int& getScore();
	void render();

protected:
	sf::RenderWindow* window;
	sf::Clock clock; //foor calcing gun timing
	int life; //for life total
	int score;
	Gun* pGun;
	int speed; //pixels per second to move
};



