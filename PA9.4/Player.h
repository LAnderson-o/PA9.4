#include "Guy.h"

class Player : public Guy {
public:
	Player() { life = 10; }

	void update(sf::FloatRect& bounds, 
		vector<Bullet*>& pBull, sf::RenderWindow* window);


private:
	int life;
	
};