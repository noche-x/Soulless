#pragma once

#include "state.h"
#include <Utilities/Timer.h>

class intro_state : public state
{
private:
    /* data */
    Stardust::Utilities::Timer* m_timer;

    Graphics::Texture* noche_texture;
    Graphics::Texture* soulless_texture;

    Graphics::Render2D::Sprite2* noche_sprite;
    Graphics::Render2D::Sprite2* soulless_sprite;
public:
    void create();
    void destroy();

    void render();
};

extern intro_state* intro_state_instance;