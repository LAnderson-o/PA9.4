#include "Enemy.h"


Enemy::Enemy(int newID, Vector2f& pos, Vector2f& nGoal)
{
	speed = 300;
	id = newID;
	goal = nGoal;

	float n1;
	mov = goal - pos;
	if (mov.x < 0) {
		n1 = atan(mov.y / mov.x) + 3.14159265;
	}
	else {
		n1 = atan(mov.y / mov.x);
	}
	float n2 = cos(n1);
	float n3 = sin(n1);
	mov.x = n2;
	mov.y = n3;


	setPosition(pos);

}

void Enemy::movement(sf::RenderWindow* window, sf::FloatRect bounds, float &dt)
{
	if (this->getPosition() == goal)
	{
		goal.x = (rand() % window->getSize().x);
		goal.y = (rand() % window->getSize().y);
	}

	else if (!bounds.contains(this->getPosition()))
	{
		goal.x = (rand() % window->getSize().x);
		goal.y = (rand() % window->getSize().y);
	}
	else
	{
		move((float) speed*mov*dt);
	}
}



void Enemy::setID(int newID)
{
	id = newID;
}
