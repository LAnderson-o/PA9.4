#pragma once

#include "GameState.h"

class Game {
public:
	//constructors
	Game();
	~Game();

	//member funcs
	void update();
	void render();
	void run();
	void updatedt();



private:

	GameState* mainGame;

	void initalizeVars();
	void initalizeWindow();

	sf::RenderWindow* window;

	sf::Event event;



	float dt; //deltatime, need to track time for frames
	sf::Clock dClock;


};