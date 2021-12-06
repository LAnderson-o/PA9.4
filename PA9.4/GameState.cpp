#include "GameState.h"



GameState::GameState(sf::RenderWindow* nWindow)
{

	initalizeTextures();
	initalizePlayer();
	initalizeBackground();
	bounds = background.getGlobalBounds();
	this->window = nWindow;
}

GameState::~GameState()
{
}

void GameState::update()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		
		if (bounds.contains(sf::Vector2f(0, player.getPosition().y+53))){
			player.move(0, 3);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (bounds.contains(sf::Vector2f(0, player.getPosition().y+20))){
			player.move(0, -3);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (bounds.contains(sf::Vector2f(player.getPosition().x, 0))){
			player.move(-3, 0);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (bounds.contains(sf::Vector2f(player.getPosition().x+50, 0))){
			player.move(3, 0);
		}
	}
}

void GameState::render()
{
	 
	window->clear(sf::Color(0, 102, 0, 0));

	window->draw(background);

	window->draw(player);

	window->display();
}


void GameState::initalizeBackground() {
	background.setTexture(backgroundTexture);
}


void GameState::initalizeTextures() {
    newTexture.loadFromFile("frog1transparent.png");
	backgroundTexture.loadFromFile("Background.png");
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
