#include "Menu.h"
//constructor & deconstructor
Menu::Menu(float width, float height)
{
	if (!this->font.loadFromFile("Fonts/Game Of Squids.ttf"))
	{
		std::cout << "ERROR::MENU::Failed to load fonts!" << "\n";
	}

	this->menu[0].setFont(this->font);
	this->menu[0].setFillColor(sf::Color::Red);
	this->menu[0].setCharacterSize(24);
	this->menu[0].setString("Play");
	this->menu[0].setPosition(sf::Vector2f(width / 2, height / (NUM_OF_ITEMS + 1) * 1));

	this->menu[1].setFont(this->font);
	this->menu[1].setFillColor(sf::Color::White);
	this->menu[1].setCharacterSize(24);
	this->menu[1].setString("Options");
	this->menu[1].setPosition(sf::Vector2f(width / 2, height / (NUM_OF_ITEMS + 1) * 2));

	this->menu[2].setFont(this->font);
	this->menu[2].setFillColor(sf::Color::White);
	this->menu[2].setCharacterSize(24);
	this->menu[2].setString("Exit");
	this->menu[2].setPosition(sf::Vector2f(width / 2, height / (NUM_OF_ITEMS + 1) * 3));
}

Menu::~Menu()
{
}

//functions
void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < NUM_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (SelecteditemIndex - 1 >= 0)
	{
		
		menu[SelecteditemIndex].setFillColor(sf::Color::White);
		SelecteditemIndex--;
		menu[SelecteditemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (SelecteditemIndex + 1 < NUM_OF_ITEMS)
	{
		menu[SelecteditemIndex].setFillColor(sf::Color::White);
		SelecteditemIndex++;
		menu[SelecteditemIndex].setFillColor(sf::Color::Red);
	}
}
//getters
int Menu::GetPressedItem()
{
	return SelecteditemIndex;
}
