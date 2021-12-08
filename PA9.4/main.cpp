#include "Game.h"

int main(){
    //sf::Font font;
    //font.loadFromFile("comic.ttf");
    Game* game = new Game();
    game->run();
    return 0;
}