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
	void updatedt();



	sf::RectangleShape roads[3];

private:

	GameState* mainGame;

	void initalizeVars();
	void initalizeWindow();

	sf::RenderWindow* window;

	sf::Event event;



	double dt; //deltatime, need to track time for frames
	sf::Clock dClock;


};