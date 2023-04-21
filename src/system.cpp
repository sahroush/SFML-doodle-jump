#include "system.hpp"

System::System(int width, int height){
    window.create(VideoMode(width, height), "doodle jump?", Style::Close);
    window.setFramerateLimit(72);
    player = new Player;
}

void System::run(){
    while (window.isOpen()){
        handle_events();
        update();
        render();
    }
}

void System::handle_key_down(Event &event){
    switch(event.key.code){
    case(Keyboard::Up):
    case(Keyboard::Space):
        player->jump();
        break;
    case(Keyboard::Left):
    case(Keyboard::A):
        player->go_left();
        break;
    case(Keyboard::Right):
    case(Keyboard::D):
        player->go_right();
        break;
    default:
        break;
    }
}

void System::handle_key_up(Event &event){
    switch(event.key.code){
    case(Keyboard::Left):
    case(Keyboard::A):
        player->stop_left();
        break;
    case(Keyboard::Right):
    case(Keyboard::D):
        player->stop_right();
        break;
    default:
        break;
    }
}

void System::handle_events(){
    Event event;
    while (window.pollEvent(event)){
        switch(event.type){
        case(Event::Closed):
            window.close();
            break;
        case(Event::KeyPressed):
            handle_key_down(event);
            break;
        case(Event::KeyReleased):
            handle_key_up(event);
            break;
        default:
            break;
        }
    }
}

void System::update(){
    player->update();
}

void System::render(){
    window.clear(Color(226, 200, 232));
    draw_player();

    window.display();
}

void System::draw_player(){
    auto [x, y] = player->get_pos();
    y = HEIGHT - y;
    auto sprite = player->get_sprite();
    sprite.setPosition(x, y);
    window.draw(sprite);
}