#include "Guy.h"

class Player : public Guy {
public:
	Player() 
	{
		life = 10; speed = 100;
		pGun = new Gun2();
	}

	void update(sf::FloatRect& bounds, 
		vector<Bullet*>& pBull, sf::RenderWindow* window, float& dt);
	bool firegun(sf::RenderWindow* nWindow, vector<Bullet*>& pBull);
	void upgrade();
	//upgread funciont should be called on certain score from GameState


	
private:
	
	
};