#pragma once

#include "global_stuff.hpp"
#include "entity.hpp"

class Player : public Entity {
public:
    Player();
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
    bool is_falling();
private:
    Texture texture;
    double vx, vy;
    double ay = 0.1;
    bool going_left = 0;
    bool going_right = 0;
    bool going_up = 0;
    bool faced_left = 0;
    SoundBuffer jump_buffer, fall_buffer;
    Sound jump_sound;
    Sound falling_sound;
    bool lost = 0;
};