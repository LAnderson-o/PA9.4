#include "Guy.h"

class Player : public Guy {
public:
	Player() { life = 10; speed = 150; }

	void update(sf::FloatRect& bounds, 
		vector<Bullet*>& pBull, sf::RenderWindow* window, double& dt);
	void rotateAroundCenter(int degrees);


private:
	int life;
	int speed; //pixels per second to move
};