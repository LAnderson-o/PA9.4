#include "Guy.h"

void Guy::setLife(int newLife) {
	life = newLife;
}

int Guy::getLife() {
	return life;
}

void Guy::render()
{
	window->draw(*this);
}
