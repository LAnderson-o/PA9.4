#pragma once
#include "GameState.h"
#include "EnemiesTest.h"
//test if enemy moves to position

class TestState4 :
    public GameState
{
public:
    TestState4(sf::RenderWindow* nWindow);
    ~TestState4();




    void update(float& dt);
    void render();

    bool gameOver(); //if fail will say then return delete self

private:

    

    void initalizeEnemies();


    bool shot;
};

