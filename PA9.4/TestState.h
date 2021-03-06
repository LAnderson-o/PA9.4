#pragma once
#include "GameState.h"
#include "Header.h"
//test if player bullet despawns enemy

class TestState1 :
    public GameState
{
public:
    TestState1(sf::RenderWindow* nWindow);
    ~TestState1();




    void update(float& dt);
    void render();

    bool gameOver(); //if fail will say then return delete self

private:

    sf::Texture enemyTexture;


    void initalizeEnemy();


    Enemy* testEnemy; //see if despawns
    bool shot;
};

