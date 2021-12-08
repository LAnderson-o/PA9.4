#include "Guy.h"

class Player : public Guy {
public:
	Player() { life = 10; speed = 150;}

	void update(sf::FloatRect& bounds, 
		vector<Bullet*>& pBull, sf::RenderWindow* window, float& dt);
	bool firegun(sf::RenderWindow* nWindow, vector<Bullet*>& pBull);

	void setLife(int newLife);
	
	int getLife();
	int getSpeed();

private:
	int life;
	int speed; //pixels per second to move
};