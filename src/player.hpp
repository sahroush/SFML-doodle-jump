#include "global_headers.hpp"

class Player {
public:
    Player();
    void draw(RenderWindow &window);
    void go_left();
    void go_right();
    void go_up();
    void go_down();
private:
    Sprite sprite;
    Texture texture;
    int x, y;
};