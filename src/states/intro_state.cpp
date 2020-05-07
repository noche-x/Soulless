#include "intro_state.h"
#include "../menu_system/menu_system.h"
#include "../state_manager.h"
#include <Utilities/Logger.h>
#include <iomanip>

intro_state* intro_state_instance = new intro_state();

void intro_state::create() {
	m_timer = new Stardust::Utilities::Timer();
	m_timer->reset();

    noche_texture = Graphics::TextureUtil::LoadPng("assets/noche.png");
    soulless_texture = Graphics::TextureUtil::LoadPng("assets/soulless.png");
    
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

int color = 0xFF000000;
template <typename T>
inline T lerp(T v0, T v1, T t) {
    return (1-t)*v0 + t*v1;
}

void intro_state::render() {
	if (noche_sprite == NULL || soulless_sprite == NULL)
        return;
    
    m_timer->deltaTime();

    lerp(0x00000000, color, 0x01000000);
    
    std::stringstream stream;
    stream << "0x" 
        << std::setfill ('0') << std::setw(sizeof(int)*2) 
        << std::hex << color;
    Utilities::app_Logger->log(stream.str());

    // if (m_timer->elapsed() > 2.0f && m_timer->elapsed() < 4.0f)
    // else if (m_timer->elapsed() > 4.0f && m_timer->elapsed() < 6.0f)
    //     soulless_sprite->draw();
    // else if (m_timer->elapsed() > 6.0f)
    //     g_state_manager.switch_to_next_state();

        noche_sprite->setColor(color);
    noche_sprite->draw();

    g_menu_system.update();
}