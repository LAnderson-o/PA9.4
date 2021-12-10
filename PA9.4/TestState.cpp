#include "TestState.h"


TestState::TestState(sf::RenderWindow* nWindow)
{
	initalizeTextures();

	initalizeBackground();
	initalizeText();
	bounds = background.getGlobalBounds();
	lost = false;
	this->window = nWindow;
	
	Vector2f temp(window->getSize().x / 2, window->getSize().y);
	int l = 3;

	testEnemy = new Enemy(window, temp, temp, l);
	
	initalizePlayer();
}
