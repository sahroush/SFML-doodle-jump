#include "player.hpp"

Player::Player(){
    if (!texture.loadFromFile("../files/jumper.png")){
        throw runtime_error("Couldn't load player image");
    }
    sprite.setTexture(texture);
    sprite.setScale(Vector2f(0.12f, 0.12f));
    sprite.setOrigin(0, sprite.getLocalBounds().height);
    vx = 0;
    vy = 0;
}

Sprite Player::get_sprite(){
    return sprite;
}

void Player::go_left(){
    if(going_left)return;
    going_left = 1;
    vx -= 3;
    if(!faced_left){
        mirrorSpriteHorizontally();
        faced_left = 1;
    }
}

void Player::go_right(){
    if(going_right)return;
    going_right = 1;
    vx += 3;
    if(faced_left){
        mirrorSpriteHorizontally();
        faced_left = 0;
    }
}  

void Player::stop_left(){
    if(!going_left)return;
    going_left = 0;
    vx += 3;
}

void Player::stop_right(){
    if(!going_right)return;
    going_right = 0;
    vx -= 3;
}

void Player::jump(){
    if(going_up)return;
    going_up = 1;
    vy -= 10;
    ay = 0.1;
}

void Player::update(){
    auto x = sprite.getPosition().x;
    auto y = sprite.getPosition().y;
    vy += ay;
    x += vx;
    y += vy;
    if(x < -sprite.getGlobalBounds().width/2){
        x = WIDTH-sprite.getGlobalBounds().width/2;
    }
    else if(x > WIDTH-sprite.getGlobalBounds().width/2){
        x = -sprite.getGlobalBounds().width/2;
    }
    sprite.setPosition(x, y);
}

void Player::set_position(int x, int y){
    sprite.setPosition(x, y);
}

bool Player::is_going_down(){
    return vy > 0;
}

void Player::stop_descent(int h){
    auto x = sprite.getPosition().x;
    auto y = sprite.getPosition().y;
    vy = 0;
    ay = 0;
    y = h;
    going_up = 0;
    sprite.setPosition(x, y);
    jump();
}