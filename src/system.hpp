#include "global_stuff.hpp"
#include "player.hpp"
#include "platform.hpp"



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
    vector <Platform*> platforms;
    Player* player;
    int dist_between_platforms = 20;
    RenderWindow window;
};