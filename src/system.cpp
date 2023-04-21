#include "system.hpp"

System::System(int width, int height){
    window.create(VideoMode(width, height), "doodle jump?", Style::Close);
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
    case(Keyboard::A):
        player->go_left();
        break;
    case(Keyboard::S):
        player->go_down();
        break;
    case(Keyboard::D):
        player->go_right();
        break;
    case(Keyboard::W):
        player->go_up();
        break;
    }
}

void System::handle_key_up(Event &event){
    
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
        }
    }
}

void System::update(){

}

void System::render(){
    window.clear(Color(226, 200, 232));
    player->draw(window);

    window.display();
}