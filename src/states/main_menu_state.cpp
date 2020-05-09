#include "main_menu_state.h"
#include "../menu_system/menu_system.h"
#include "../state_manager.h"
#include <Utilities/Logger.h>

main_menu_state* main_menu_state_instance = new main_menu_state();

bool m_change = false;

void play_button_click() {
    m_change = true;
}

void credits_button_click() {
    
}

void exit_button_click() {
    
}

void main_menu_state::create() {
    non_selected_button_texture = Graphics::TextureUtil::LoadPng("assets/selected.png");
    selected_button_texture = Graphics::TextureUtil::LoadPng("assets/non-selected.png");
    ghost_texture = Graphics::TextureUtil::LoadPng("assets/ghost.png");
    logo_texture = Graphics::TextureUtil::LoadPng("assets/logo.png");
    
	ghost_sprite = new Graphics::Render2D::Sprite2(ghost_texture, {212, 320});
	ghost_sprite->position(400, 200);
	logo_sprite = new Graphics::Render2D::Sprite2(logo_texture, {231, 47});
	logo_sprite->position(240, 43);
    logo_sprite->scale(1, 1);
    logo_sprite->setColor(0, 0, 0, 255);

    play_text = new Graphics::UI::UIText({ 70, 70 }, "play");
    play_button = new Graphics::UI::UIButton({156, 110}, {128, 32}, non_selected_button_texture, selected_button_texture, play_text);

    credits_text = new Graphics::UI::UIText({ 70, 70 }, "credits");
    credits_button = new Graphics::UI::UIButton({156, 150}, {128, 32}, non_selected_button_texture, selected_button_texture, credits_text);

    exit_text = new Graphics::UI::UIText({ 70, 70 }, "exit");
    exit_button = new Graphics::UI::UIButton({156, 190}, {128, 32}, non_selected_button_texture, selected_button_texture, exit_text);

    play_button->setPosition({156, 110});
    credits_button->setPosition({156, 150});
    exit_button->setPosition({156, 190});

    g_menu_system.add_button(play_button);
    g_menu_system.add_button(credits_button);
    g_menu_system.add_button(exit_button);

    g_menu_system.set_button_action(1, play_button_click);
    g_menu_system.set_button_action(2, credits_button_click);
    g_menu_system.set_button_action(3, exit_button_click);

    m_change = false;
}

void main_menu_state::destroy() {
    delete non_selected_button_texture;
    delete selected_button_texture;

    delete logo_texture;
    delete ghost_texture;

    delete logo_sprite;
    delete ghost_sprite;

    delete play_text;
    delete play_button;

    delete credits_text;
    delete credits_button;

    delete exit_text;
    delete exit_button;
}

void main_menu_state::render() {
	if (ghost_sprite == NULL || logo_sprite == NULL)
        return;

    if (m_change)
        g_state_manager.switch_to_next_state();

	logo_sprite->position(240, 43);
    logo_sprite->scale(1, 1);
    logo_sprite->setColor(0, 0, 0, 255);
    
    ghost_sprite->draw();
    logo_sprite->draw();
    g_menu_system.update();
}