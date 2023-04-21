#pragma once

#include "global_stuff.hpp"

class Entity{
public:
    Entity();
    bool collides_with(Sprite other);
protected:
    Sprite sprite;
    void mirrorSpriteHorizontally();
private:

};