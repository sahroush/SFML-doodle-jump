#include "system.hpp"

System::System(int width, int height){
    window.create(VideoMode(width, height), "doodle jump?", Style::Close);
    camera = View(FloatRect(0, 0, window.getSize().x, window.getSize().y));
    camera.setCenter(window.getSize().x, window.getSize().y);   
    window.setView(camera);
    window.setFramerateLimit(60);
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
    mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
    if(player->is_going_down()){
        for(auto platform : platforms)
            if(player->collides_with(platform->get_sprite())){
                player->stop_descent(platform->get_h());
                break;
            }
    }
    player->update();
    Sprite sprite = player->get_sprite();
    camera.setCenter(WIDTH/2, sprite.getPosition().y);
    height = min(height, int(sprite.getPosition().y));
    window.setView(camera);
    while(height - max_height < HEIGHT){
        max_height -= dist_between_platforms;
        for(int i = 0 ; i < (int)rng()%1 + 1 ; i ++)
            platforms.push_back(new Platform(max_height));
    }
    while(platforms.size() and height - platforms.front()->get_h() > 100){
        platforms.pop_front();
    }
    cout << platforms.size() << endl;
}

void System::render(){
    window.clear(Color(226, 200, 232));
    draw_player();
    for(auto platform : platforms)
        window.draw(platform->get_sprite());
    window.display();
}

void System::draw_player(){
    auto [x, y] = player->get_pos();
    y = HEIGHT - y;
    auto sprite = player->get_sprite();
    sprite.setPosition(x, y);
    player->set_position(x, y);
    window.draw(sprite);
}