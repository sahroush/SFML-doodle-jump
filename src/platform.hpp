#pragma once

#include "global_stuff.hpp"
#include "entity.hpp"

class Platform : private Entity{
public:
    Platform(int h_);
    int get_h();
    Sprite get_sprite();
private:
    Texture texture;
    int h;
    int x;
};