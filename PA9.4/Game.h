#pragma once

#include "TestState.h"
#include "TestState2.h"
#include "TestState3.h"
#include "TestState4.h"
#include "TestState5.h"
#include "GameState.h"
#include "Game.h"

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