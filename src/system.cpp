#include "system.hpp"

System::System(int width, int height){
    window.create(VideoMode(width, height), "doodle jump?", Style::Close);
    camera = View(FloatRect(0, 0, window.getSize().x, window.getSize().y));
    camera.setCenter(window.getSize().x, window.getSize().y);   
    window.setView(camera);
    window.setFramerateLimit(144);
    player = new Player;

    if (!font.loadFromFile("../files/mangat.ttf")) {
        throw runtime_error("Could not load font");
    }

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
        //player->jump();
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

void System::lose_phase(){
    int player_h = player->get_sprite().getPosition().y;
    int camera_h = camera.getCenter().y;
    if(player_h - camera_h < HEIGHT){
        player->update();
        window.setView(camera);
    }
    else{
        game_over = 1;
    }
}

void System::update(){
    if(player->is_falling()){
        lose_phase();        
        return;
    }
    mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
    Sprite sprite = player->get_sprite();
    if(player->is_going_down()){
        for(auto platform : platforms)
            if(player->collides_with(platform->get_sprite())){
                player->stop_descent(platform->get_h());
                break;
            }
    }
    player->update();
    camera.setCenter(WIDTH/2, sprite.getPosition().y);
    height = min(height, int(sprite.getPosition().y));
    window.setView(camera);
    while(height - max_height < HEIGHT){
        max_height -= dist_between_platforms;
        for(int i = 0 ; i < (int)rng()%1 + 1 ; i ++)
            platforms.push_back(new Platform(max_height));
    }
    while(platforms.size() and platforms.front()->get_h() - height > 2*HEIGHT){
        platforms.pop_front();
    }
}

void System::render(){
    window.clear(Color(226, 200, 232));
    if(!game_over){
        draw_player();
        for(auto platform : platforms)
            window.draw(platform->get_sprite());
    }
    else{
        //cout << "Aaaaaaaaaa" << endl;
        sf::Text text("Game Over!", font, 50);
        text.setFillColor(sf::Color::Black);
        text.setPosition(-WIDTH/2 + 90, 0);
        camera.setCenter(0, 0);
        window.setView(camera);
        window.draw(text);
        static auto start_time = std::chrono::high_resolution_clock::now();
        auto end_time = std::chrono::high_resolution_clock::now();
        auto elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count();
        if(elapsed_seconds >= 3){
            window.close();
            return;
        }
    }
    window.display();
}

void System::draw_player(){
    auto sprite = player->get_sprite();
    window.draw(sprite);
}