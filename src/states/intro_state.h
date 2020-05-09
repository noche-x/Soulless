#pragma once

#include "state.h"
#include <Utilities/Timer.h>

class intro_state : public state
{
private:
    /* data */
    Stardust::Utilities::Timer* m_timer;
    Stardust::Utilities::Timer* anim_timer;

    Graphics::Texture* soulless_texture;

    Graphics::Render2D::Sprite2* soulless_sprite;

    bool m_changing;
    Graphics::UI::UIText* noche_text_anim;
public:
    void create();
    void destroy();

    void render();
};

extern intro_state* intro_state_instance;