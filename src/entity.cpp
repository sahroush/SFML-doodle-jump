#include "entity.hpp"

Entity::Entity(){

}

void Entity::mirrorSpriteHorizontally() {
    // Get the current scale of the sprite
    sf::Vector2f scale = sprite.getScale();
    
    // Set the sprite's scale to mirror horizontally
    sprite.setScale(-scale.x, scale.y);
    
    // Get the current origin of the sprite
    sf::Vector2f origin = sprite.getOrigin();
    
    // Adjust the origin to mirror horizontally
    origin.x = sprite.getLocalBounds().width - origin.x;
    
    // Set the new origin for the sprite
    sprite.setOrigin(origin);
}
