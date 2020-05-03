#include "state.h"

class intro_state : public state
{
private:
    /* data */
    Graphics::Texture* non_selected_button_texture;
    Graphics::Texture* selected_button_texture;

    Graphics::UI::FontStyle style;

    Graphics::UI::UIText* title_text;
    
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
