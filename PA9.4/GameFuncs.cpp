#include "Game.h"

Game::Game() {
	initalizeVars();
	initalizeWindow();
    initalizeTextures();
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
                //std::cout << player.getPosition().x << std::endl;
                if(player.getPosition().x > 0){
                    player.move(-5, 0);
                }
            }
            else if (event.key.code == sf::Keyboard::D) {
                //std::cout << player.getPosition().x << std::endl;
                if (player.getPosition().x < window->getSize().x - newTexture.getSize().x * 2) {
                    player.move(5, 0);
                }
            } else if (event.key.code == sf::Keyboard::Space) {
                //player.shoot
            }
            break;
        }
    }

    
}

void Game::render() {
    window->clear(sf::Color(0, 102, 0, 0));
    
    //draw here
    for (int i = 0; i < 3; i++) { // this for loop isnt working or someething to do with roads
        window->draw(roads[i]);
    }
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
    player.setTexture(newTexture);
    player.setScale(sf::Vector2f(2.f,2.f));
    //looks
    /*player.setSize(sf::Vector2f(50.f, 50.f));
    player.setFillColor(sf::Color::White);
    player.setOutlineColor(sf::Color::Black);
    player.setOutlineThickness(1.f);*/
}

void Game::initalizeBackground() {
    //roads
    for (int i = 0; i < 3; i++) {
        roads[i].setFillColor(sf::Color(64, 64, 64, 0));
        int tempwidth = window->getSize().x;
        roads[i].setSize(sf::Vector2f(tempwidth, 60));
        roads[i].setPosition(0, ((window->getSize().y/3)*i+1)-60);
    }
}

void Game::initalizeVars() {
	window = nullptr;
}

void Game::initalizeTextures() {
    newTexture.loadFromFile("frog1transparent.png");
}

void Game::initalizeWindow() {
	window = new sf::RenderWindow(sf::VideoMode(640, 480), "PA9", sf::Style::Default);//change window size here
    window->setFramerateLimit(30);
}