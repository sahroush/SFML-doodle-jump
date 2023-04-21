#pragma once

#include "global_stuff.hpp"
#include "entity.hpp"

class Player : public Entity {
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
    void set_position(int x, int y);
    bool is_going_down();
    void stop_descent(int h);
private:
    Texture texture;
    int x, y;
    int vx, vy;
    int ay = -1;
    bool going_left = 0;
    bool going_right = 0;
    bool going_up = 0;
    bool faced_left = 0;
};