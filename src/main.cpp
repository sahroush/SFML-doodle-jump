#include "global_headers.hpp"
#include "system.hpp"


const int WIDTH = 400;
const int HEIGHT = 800;


int main(){
    //This is the product of OOP overuse
    System game(WIDTH, HEIGHT);    
    game.run();
    return 0;
}