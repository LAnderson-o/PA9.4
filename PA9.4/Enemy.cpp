#include "Enemy.h"


Enemy::Enemy(sf::RenderWindow* nWindow, Vector2f& pos, Vector2f& nGoal, int& nLife)
{
	window = nWindow;
	shotTime = rand() % 10000;

	
	life = nLife;
	speed = 150;
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

	wMov.x = -n3;
	wMov.y = n2;


	setPosition(pos);
	pGun = new Gun();
}

void Enemy::movement(float &dt)
{
	
	if ((this->getPosition() - goal).x > 0 && (this->getPosition() - goal).x < 10) //when fly is 'at' goal pos
	{//had to make it 'near' as it would just jump over goal
		goal.x = (rand() % window->getSize().x); //generate new goal
		goal.y = (rand() % window->getSize().y);

		float n1;
		mov = goal - getPosition(); 
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
	}

	else
	{

		move(speed*mov*dt +  100*sin((float)mClock.getElapsedTime().asMilliseconds()/5)*wMov*dt);
	}
}

bool Enemy::firegun(vector<Bullet*>& eBull, Vector2f& target)
{
	
	if (clock.getElapsedTime().asMilliseconds() > shotTime && clock.getElapsedTime().asSeconds() > 2)
	{
		shotTime = rand() % 10000;
		clock.restart();

		return pGun->fireBullet(this->getPosition(), target, eBull);

	}
	
	return false;

}

