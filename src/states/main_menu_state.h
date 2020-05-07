#pragma once

#include "state.h"

class main_menu_state : public state
{
private:
    /* data */
    Graphics::Texture* non_selected_button_texture;
    Graphics::Texture* selected_button_texture;
    Graphics::Texture* ghost_texture;
    Graphics::Texture* logo_texture;

    Graphics::Render2D::Sprite2* ghost_sprite;
    Graphics::Render2D::Sprite2* logo_sprite;

    Graphics::UI::FontStyle style;
    
    Graphics::UI::UIText* play_text;
    Graphics::UI::UIButton* play_button;

    Graphics::UI::UIText* options_text;
    Graphics::UI::UIButton* options_button;
    
    Graphics::UI::UIText* credits_text;
    Graphics::UI::UIButton* credits_button;

    Graphics::UI::UIText* exit_text;
    Graphics::UI::UIButton* exit_button;
public:
    void create();
    void destroy();

    void render();
};

extern main_menu_state* main_menu_state_instance;