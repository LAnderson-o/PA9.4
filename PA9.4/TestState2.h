#pragma once
#include "GameState.h"
//test if bullet decreases life

class TestState2 :
    public GameState
{

public:
    TestState2(sf::RenderWindow* nWindow);
    ~TestState2();




    void update(float& dt);
    void render();

    bool gameOver(); //if fail will say then return delete self

private:

    sf::Texture enemyTexture;


    void initalizeEnemy();


    Enemy* testEnemy; //see if despawns
    bool shot;


};

