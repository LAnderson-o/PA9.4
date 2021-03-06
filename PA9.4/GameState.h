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
    GameState(); //for inheratance
    GameState(sf::RenderWindow* nWindow);
    ~GameState();

    virtual void update(float& dt);
    virtual void render();
    
    virtual bool gameOver();
    void tutor();

protected:
    int score;
    
    bool start;

    virtual void updateBul(float& dt);

    
    void initalizePlayer();
    virtual void initalizeEnemies();
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
    sf::Text tutortext;
    bool lost;
    
    Enemies* enemies;
    Player* user;
    sf::Sprite background;


    //may make BulletManager class that contains these and manages them
    vector<Bullet*> pBull; //vector of player bullets
    vector<Bullet*> eBull; //vector of enemy bullets


    //vector<sf::Texture> tex; //textures

};