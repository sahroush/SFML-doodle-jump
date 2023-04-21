#include "global_stuff.hpp"
#include "system.hpp"

int main(){
    //This is the product of OOP overuse
    System game(WIDTH, HEIGHT);    
    game.run();
    return 0;
}