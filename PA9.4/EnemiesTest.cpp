#include "EnemiesTest.h"

void EnemiesTest::update(sf::FloatRect bounds, float& dt, vector<Bullet*>& pBull, vector<Bullet*>& eBull, Vector2f pPos, int& score)
{



	//loop through all enemies check if bullet intersects enemy
	for (int i = 0; i < enemyList.size(); ++i) {
		enemyList[i]->movement(dt);
		enemyList[i]->firegun(eBull, pPos);
		for (int j = 0; j < pBull.size(); ++j) {
			if (enemyList[i]->getGlobalBounds().intersects(pBull[j]->getGlobalBounds())) {

				delete pBull[j];
				pBull.erase(pBull.begin() + j);



				score++; //updates game score (might be hitting twice)
				delete enemyList[i];
				enemyList.erase(enemyList.begin() + i);
				break; //tinker with this alter

				//delete bullet 


			}
		}
	}

}
