#include "Guy.h"

void Guy::setLife(int newLife) {
	life = newLife;
}

int Guy::getLife() {
	return life;
}

void Guy::setScore(int newScore) {
	score = newScore;
}

int& Guy::getScore() {
	return score;
}