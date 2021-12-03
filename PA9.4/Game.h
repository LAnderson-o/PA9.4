#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Game {
public:
	//constructors
	Game();
	virtual ~Game();

	//member funcs
	void update();
	void render();
	void run();

	sf::RectangleShape player;

private:
	sf::RenderWindow* window;
	sf::Event event;

	void initalizePlayer();
	void initalizeVars();
	void initalizeWindow();
};