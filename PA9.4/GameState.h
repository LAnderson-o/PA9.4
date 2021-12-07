#pragma once

//will use to create "game states" like main game



#include "Player.h"
#include "Guy.h"
#include "Enemies.h"
//#include "Player.h"
//#include "Enemy.h"

class GameState
{
public:
    GameState(sf::RenderWindow* nWindow);
    ~GameState();

    void update();
    void render();
    


private:
    void initalizePlayer();
    void initalizeEnemies();
    void initalizeBackground();
    void initalizeTextures();
    
    sf::RenderWindow* window;
    sf::Texture playerTexture[3];
    sf::Texture backgroundTexture;
    sf::FloatRect bounds;


    
    Enemies enemies;
    Guy player;
    sf::Sprite background;

    vector<Bullet*> pBull; //vector of player bullets
    //vector<Bullet> eBull; //vector of enemy bullets


    //vector<sf::Texture> tex; //textures

};

