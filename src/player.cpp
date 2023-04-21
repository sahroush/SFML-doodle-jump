#include "player.hpp"

Player::Player(){
    if (!texture.loadFromFile("../files/jumper.png")){
        throw runtime_error("Couldn't load player image");
    }
    sprite.setTexture(texture);
    sprite.setScale(Vector2f(0.12f, 0.12f));
    x = y = 0;
};

void Player::draw(RenderWindow &window){
    sprite.setPosition(x, y);
    window.draw(sprite);
}

void Player::go_down(){
    y += 10;
}

void Player::go_up(){
    y -= 10;
}

void Player::go_left(){
    x -= 10;
}

void Player::go_right(){
    x += 10;
}