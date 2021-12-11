#pragma once
#include "GameState.h"
#include "EnemiesTest.h"
#include "Header.h"
//test if score updates

class TestState3 :
    public GameState
{
public:
    TestState3(sf::RenderWindow* nWindow);
    ~TestState3();




    void update(float& dt);
    void render();

    bool gameOver(); //if fail will say then return delete self

private:
    virtual void updateBul(float& dt);

    void initalizeEnemies();


    bool shot;
};

