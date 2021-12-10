#include "Guy.h"
#include "bullet.h"

class Player : public Guy {
public:
	Player(sf::RenderWindow* nWindow)
	{
		
		firstShot = true;
		life = 10; speed = 100;
		pGun = new Gun();
		window = nWindow;
	}

	void update(sf::FloatRect& bounds, 
		vector<Bullet*>& pBull, sf::RenderWindow* window, float& dt);
	bool firegun(sf::RenderWindow* nWindow, vector<Bullet*>& pBull);
	void upgrade();
	//upgread funciont should be called on certain score from GameState


	
private:
	bool firstShot;
	
};