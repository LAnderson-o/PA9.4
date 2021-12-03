#include "Game.h"

Game::Game() {
	initalizeVars();
	initalizeWindow();
    initalizePlayer();
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
            if (event.key.code == sf::Keyboard::Escape) {
                window->close();
            } else if(event.key.code == sf::Keyboard::A) {
                player.move(-5, 0);
            } else if (event.key.code == sf::Keyboard::D) {
                player.move(5, 0);
            }
            break;
        }
    }
    
}

void Game::render() {
    window->clear(sf::Color::Magenta);
    
    //draw here
    window->draw(player);
    
    window->display();
}

void Game::run() {
    while (window->isOpen()) {
        update();
        render();
    }
}

void Game::initalizePlayer() {
    //position
    player.setPosition(window->getSize().x/2, window->getSize().y-50);

    //looks
    player.setSize(sf::Vector2f(50.f, 50.f));
    player.setFillColor(sf::Color::White);
    player.setOutlineColor(sf::Color::Black);
    player.setOutlineThickness(1.f);
}

void Game::initalizeVars() {
	window = nullptr;
}

void Game::initalizeWindow() {
	window = new sf::RenderWindow(sf::VideoMode(640, 480), "PA9", sf::Style::Default);//change window size here
    window->setFramerateLimit(30);
}