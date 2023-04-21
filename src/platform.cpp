#include "platform.hpp"

Platform::Platform(int h_){
    static mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
    h = h_ + rng()%200;
    if (!texture.loadFromFile("../files/platform.png")){
        throw runtime_error("Couldn't load player image");
    }
    sprite.setTexture(texture);
    sprite.setScale(Vector2f(0.5, 0.5));
    x = rng()%int(WIDTH - sprite.getGlobalBounds().width);
    sprite.setPosition(x, h);
};

int Platform::get_h(){
    return h;
}

Sprite Platform::get_sprite(){
    return sprite;
}