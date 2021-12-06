#include "GameState.h"



GameState::GameState(sf::RenderWindow* nWindow)
{

	initalizeTextures();
	initalizePlayer();
	this->window = nWindow;
}

GameState::~GameState()
{
}

void GameState::update()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		player.move(0, 1);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player.move(0, -1);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player.move(-1, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player.move(1, 0);
	}
}

void GameState::render()
{
	 
	window->clear(sf::Color(0, 102, 0, 0));

	window->draw(player);

	window->display();
}


void GameState::initalizeBackground() {
    ////roads
    //for (int i = 0; i < 3; i++) {
    //    roads[i].setFillColor(sf::Color(64, 64, 64, 0));
    //    int tempwidth = window->getSize().x;
    //    roads[i].setSize(sf::Vector2f(tempwidth, 60));
    //    roads[i].setPosition(0, ((window->getSize().y / 3) * i + 1) - 60);
    //}
}


void GameState::initalizeTextures() {
    newTexture.loadFromFile("frog1transparent.png");
}


void GameState::initalizePlayer() {
    //position
    player.setPosition(400, 100);
    player.setTexture(newTexture);
    player.setScale(sf::Vector2f(2.f, 2.f));
    //looks
    /*player.setSize(sf::Vector2f(50.f, 50.f));
    player.setFillColor(sf::Color::White);
    player.setOutlineColor(sf::Color::Black);
    player.setOutlineThickness(1.f);*/
}
