#include "Game.h"

Game::Game() {
	initalizeVars();
	initalizeWindow();
}

Game::~Game() {
	delete window;
}

void Game::update() {
    //event poll
    while (window->pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed://this is how we can update player movement
            if (event.key.code == sf::Keyboard::Escape)
                window->close();
            break;
        }
    }
    
}

void Game::render() {
    window->clear(sf::Color::Magenta);
    //draw here
    window->display();
}

void Game::run() {
    while (window->isOpen()) {
        update();
        render();
    }
}

void Game::initalizeVars() {
	window = nullptr;
}

void Game::initalizeWindow() {
	window = new sf::RenderWindow(sf::VideoMode(1280, 960), "PA9", sf::Style::Default);//change window size here
}