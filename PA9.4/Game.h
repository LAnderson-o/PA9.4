#pragma once

#include "GameState.h"

class Game {
public:
	//constructors
	Game();
	virtual ~Game();

	//member funcs
	void update();
	void render();
	void run();
	


	sf::RectangleShape roads[3];

private:

	GameState* mainGame;

	void initalizeVars();
	void initalizeWindow();

	sf::RenderWindow* window;

	sf::Event event;


};