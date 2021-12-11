#pragma once
#include "GameState.h"

#include "Header.h"

//test if bullet despawns on impact
class TestState5 : public GameState
{
public:
    TestState5(sf::RenderWindow* nWindow);
    ~TestState5();




    void update(float& dt);
    void render();

    bool gameOver(); //if fail will say then return delete self

private:

    void updateBul(float& dt);


    int shot;
};

