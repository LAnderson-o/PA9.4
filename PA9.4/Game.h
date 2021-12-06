#pragma once

#include "Player.h"

class Game {
public:
	//constructors
	Game();
	virtual ~Game();

	//member funcs
	void update();
	void render();
	void run();

	Player player;
	sf::Texture newTexture;
	sf::RectangleShape roads[3];

private:
	sf::RenderWindow* window;
	sf::Event event;

	void initalizePlayer();
	void initalizeBackground();
	void initalizeVars();
	void initalizeTextures();
	void initalizeWindow();
};