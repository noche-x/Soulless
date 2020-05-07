#include "main_menu_state.h"
#include "../menu_system/menu_system.h"
#include <Utilities/Logger.h>

main_menu_state* main_menu_state_instance = new main_menu_state();

void main_menu_state::create() {
    non_selected_button_texture = Graphics::TextureUtil::LoadPng("assets/non-selected.png");
    selected_button_texture = Graphics::TextureUtil::LoadPng("assets/selected.png");
    ghost_texture = Graphics::TextureUtil::LoadPng("assets/ghost.png");
    logo_texture = Graphics::TextureUtil::LoadPng("assets/logo.png");
    
	ghost_sprite = new Graphics::Render2D::Sprite2(ghost_texture, {212, 320});
	ghost_sprite->position(400, 200);
	logo_sprite = new Graphics::Render2D::Sprite2(logo_texture, {231, 47});
	logo_sprite->position(240, 43);

    play_text = new Graphics::UI::UIText({ 70, 70 }, "play");
    play_button = new Graphics::UI::UIButton({156, 100}, {120, 40}, non_selected_button_texture, selected_button_texture, play_text);

    options_text = new Graphics::UI::UIText({ 70, 70 }, "options");
    options_button = new Graphics::UI::UIButton({156, 100}, {120, 40}, non_selected_button_texture, selected_button_texture, options_text);

    credits_text = new Graphics::UI::UIText({ 70, 70 }, "credits");
    credits_button = new Graphics::UI::UIButton({156, 100}, {120, 40}, non_selected_button_texture, selected_button_texture, credits_text);

    exit_text = new Graphics::UI::UIText({ 70, 70 }, "exit");
    exit_button = new Graphics::UI::UIButton({156, 100}, {120, 40}, non_selected_button_texture, selected_button_texture, exit_text);

    play_button->setTextRelative({0, -3});
    options_button->setTextRelative({0, -3});
    credits_button->setTextRelative({0, -3});
    exit_button->setTextRelative({0, -3});

    play_button->setPosition({156, 110});
    options_button->setPosition({156, 150});
    credits_button->setPosition({156, 190});
    exit_button->setPosition({156, 230});

    g_menu_system.add_button(play_button);
    g_menu_system.add_button(options_button);
    g_menu_system.add_button(credits_button);
    g_menu_system.add_button(exit_button);
}

void main_menu_state::destroy() {
    delete non_selected_button_texture;
    delete selected_button_texture;

    delete play_text;
    delete play_button;

    delete options_text;
    delete options_button;

    delete credits_text;
    delete credits_button;

    delete exit_text;
    delete exit_button;
}

void main_menu_state::render() {
	if (ghost_sprite == NULL || logo_sprite == NULL)
        return;

    ghost_sprite->draw();
    logo_sprite->draw();
    g_menu_system.update();
}