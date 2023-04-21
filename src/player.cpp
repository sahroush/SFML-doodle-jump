#include "player.hpp"

Player::Player(){
    if (!texture.loadFromFile("../files/jumper.png")){
        throw runtime_error("Couldn't load player image");
    }
    sprite.setTexture(texture);
    sprite.setScale(Vector2f(0.12f, 0.12f));
    sprite.setOrigin(0, sprite.getLocalBounds().height);
    x = y = 0;
    vx = 0;
    vy = 0;
}

pii Player::get_pos(){
    return {x, y};
}

Sprite Player::get_sprite(){
    return sprite;
}

void Player::go_left(){
    if(going_left)return;
    going_left = 1;
    vx -= 10;
    if(!faced_left){
        mirrorSpriteHorizontally();
        faced_left = 1;
    }
}

void Player::go_right(){
    if(going_right)return;
    going_right = 1;
    vx += 10;
    if(faced_left){
        mirrorSpriteHorizontally();
        faced_left = 0;
    }
}  

void Player::stop_left(){
    if(!going_left)return;
    going_left = 0;
    vx += 10;
}

void Player::stop_right(){
    if(!going_right)return;
    going_right = 0;
    vx -= 10;
}

void Player::jump(){
    if(going_up)return;
    going_up = 1;
    vy += 23;
    ay = -1;
}

void Player::update(){
    vy += ay;
    x += vx;
    y += vy;
    if(y < 0){
        vy = 0;
        y = 0;
        going_up = 0;
    }
    if(x < -sprite.getGlobalBounds().width/2){
        x = WIDTH-sprite.getGlobalBounds().width/2;
    }
    else if(x > WIDTH-sprite.getGlobalBounds().width/2){
        x = -sprite.getGlobalBounds().width/2;
    }
}

void Player::set_position(int x, int y){
    sprite.setPosition(x, y);
}

bool Player::is_going_down(){
    return vy < 0;
}

void Player::stop_descent(int h){
    vy = 0;
    ay = 0;
    y += h;
    going_up = 0;
}