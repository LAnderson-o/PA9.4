#pragma once
#include "GameState.h"

//will close the program on failure

class TestState :
    public GameState
{
public:
    TestState(sf::RenderWindow* nWindow);
    ~TestState();



    void update(float& dt);
    
    void gameOver(); //if fail will say then return delete self

private:
    Enemy* testEnemy; //see if despawns

};

