#include "Game.h"

Game::Game() {
    initalizeVars();
    initalizeWindow();

    //mainGame = new GameState(window); 
    mainGame = new TestState5(window);
}

Game::~Game() {
    delete window;
}


void Game::updatedt()
{
    dt = dClock.restart().asSeconds();
}

void Game::update()
{


    mainGame->update(dt);


    //event polling, might need something else
    while (window->pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:

            window->close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape) {
                window->close();
            }
            break;
        }
    }

    updatedt();
}




void Game::render()
{

    //draw 
    mainGame->render();

}

void Game::run() {
    while (window->isOpen())
    {
       
        update();
        render();
    }

}


void Game::initalizeVars() {
    window = nullptr;
}



void Game::initalizeWindow() {
    window = new sf::RenderWindow(sf::VideoMode(640, 480), "PA9", sf::Style::Default);//change window size here
    window->setFramerateLimit(30);
}