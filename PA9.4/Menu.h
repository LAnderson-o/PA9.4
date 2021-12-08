#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

#define NUM_OF_ITEMS 3
class Menu
{
public:
	//constructor & deconstructor
	Menu(float width, float height);
	~Menu();

	//functions
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

private:
	int itemIndex;
	sf::Font font;
	sf::Text menu[NUM_OF_ITEMS];
};



