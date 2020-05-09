#pragma once
#include "enemy.h"

using namespace Stardust;

class normal_enemy : public enemy {
public:
	normal_enemy(glm::vec2 spawn_pos, Graphics::Render2D::Tilemap* physics_tilemap, std::string texture_file = "assets/other_char.png");

	void draw();
	void tick();
	void update();
	void handle_action(int action);
    Graphics::Render2D::TopDownController* controller;
private:
    Graphics::Texture* char_texture;
    Graphics::Render2D::CharacterSprite* char_sprite;

};