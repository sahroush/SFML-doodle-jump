#pragma once

#include "global_stuff.hpp"
#include "player.hpp"
#include "platform.hpp"
#include "entity.hpp"



class System{
public:
    System(int width, int height);
    void run();

private:
    void update();
    void render();
    void handle_events();
    void handle_key_up(Event &event);
    void handle_key_down(Event &event);
    void draw_player();
    deque <Platform*> platforms;
    Player* player;
    int dist_between_platforms = 100;
    RenderWindow window;
    View camera;
    int height = 0;
    int max_height = 3*HEIGHT;
};