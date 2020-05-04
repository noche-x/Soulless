#include "intro_state.h"
#include "../menu_system/menu_system.h"

void intro_state::create() {
    noche_texture = Graphics::TextureUtil::LoadPng("assets/non-selected.png");
    soulless_texture = Graphics::TextureUtil::LoadPng("assets/selected.png");
    
	noche_sprite = new Graphics::Render2D::Sprite2(noche_texture, {212, 320});
	noche_sprite->position(400, 200);
	soulless_sprite = new Graphics::Render2D::Sprite2(soulless_texture, {231, 47});
	soulless_sprite->position(240, 43);
}

void intro_state::destroy() {
    delete noche_texture;
    delete soulless_texture;

    delete noche_sprite;
    delete soulless_sprite;
}

void intro_state::render() {
    noche_sprite->draw();
    soulless_sprite->draw();
    g_menu_system.update();
}