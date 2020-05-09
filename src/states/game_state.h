#pragma once

#include "state.h"
#include <Utilities/Timer.h>
#include <Graphics/2D/Tilemap.h>
#include <Graphics/2D/SpriteBase.h>
#include <Graphics/2D/TopDownController.h>
#include "../ai/normal_enemy.h"

class game_state : public state
{
private:
    /* data */
    Graphics::Texture *textures;
    Graphics::TextureAtlas *texture_atlas;

    Graphics::Render2D::Tilemap *texture_tilemap;

    Graphics::Texture* char_texture;
    Graphics::Render2D::CharacterSprite* char_sprite;

    Graphics::Render2D::TopDownController* controller;

	std::vector<normal_enemy*> enemeys;
public:
    void create();
    void destroy();

    void render();
};

extern game_state *game_state_instance;