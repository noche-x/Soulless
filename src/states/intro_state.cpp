#include "intro_state.h"

void intro_state::create() {
    non_selected_button_texture = Graphics::TextureUtil::LoadPng("assets/non-selected.png");
    selected_button_texture = Graphics::TextureUtil::LoadPng("assets/selected.png");

    title_text = new Graphics::UI::UIText({ 240, 50 }, "soulless");
    
    play_text = new Graphics::UI::UIText({ 70, 70 }, "play");
    play_button = new Graphics::UI::UIButton({156, 100}, {120, 40}, non_selected_button_texture, selected_button_texture, play_text);

    options_text = new Graphics::UI::UIText({ 70, 70 }, "options");
    options_button = new Graphics::UI::UIButton({156, 100}, {120, 40}, non_selected_button_texture, selected_button_texture, options_text);

    credits_text = new Graphics::UI::UIText({ 70, 70 }, "credits");
    credits_button = new Graphics::UI::UIButton({156, 100}, {120, 40}, non_selected_button_texture, selected_button_texture, credits_text);

    exit_text = new Graphics::UI::UIText({ 70, 70 }, "exit");
    exit_button = new Graphics::UI::UIButton({156, 100}, {120, 40}, non_selected_button_texture, selected_button_texture, exit_text);

    style.size = 1.3f;
    style.color = 0xFF000000;
    style.options = INTRAFONT_ALIGN_CENTER;

    play_button->setPosition({156, 110});
    options_button->setPosition({156, 150});
    credits_button->setPosition({156, 190});
    exit_button->setPosition({156, 230});
    play_text->setOptions(style);
}

void intro_state::destroy() {
    delete non_selected_button_texture;
    delete selected_button_texture;

    delete title_text;

    delete play_text;
    delete play_button;

    delete options_text;
    delete options_button;

    delete credits_text;
    delete credits_button;

    delete exit_text;
    delete exit_button;
}

void intro_state::render() {
    title_text->draw();
    play_button->draw();    
    options_button->draw();    
    credits_button->draw();        
    exit_button->draw();      
}