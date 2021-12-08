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

    void update(float& dt);
    void render();
    
    void gameOver();


private:
    

    void updateBul(float& dt);

    
    void initalizePlayer();
    void initalizeEnemies();
    void initalizeBackground();
    void initalizeTextures();
    void initalizeText();
    
    
    
    sf::RenderWindow* window;
    sf::Texture playerTexture;
    sf::Texture backgroundTexture;
    sf::FloatRect bounds;
    sf::Font scoreFont;
    sf::Text scoreText;
    sf::Text lifeText;
    sf::Text gameovertext;
    bool lost;
    
    Enemies enemies;
    Player user;
    sf::Sprite background;


    //may make BulletManager class that contains these and manages them
    vector<Bullet*> pBull; //vector of player bullets
    vector<Bullet*> eBull; //vector of enemy bullets


    //vector<sf::Texture> tex; //textures

};