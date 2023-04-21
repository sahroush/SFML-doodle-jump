#pragma once

#include "global_stuff.hpp"
#include "entity.hpp"

class Player : private Entity {
public:
    Player();
    pii get_pos();
    Sprite get_sprite();
    void go_left();
    void go_right();
    void stop_left();
    void stop_right();
    void jump();
    void update();
private:
    Texture texture;
    int x, y;
    int vx, vy;
    int ay = -2;
    bool going_left = 0;
    bool going_right = 0;
    bool going_up = 0;
};