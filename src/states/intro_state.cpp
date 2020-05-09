#include "intro_state.h"
#include "../menu_system/menu_system.h"
#include "../state_manager.h"
#include <Utilities/Logger.h>
#include <iomanip>
#include <algorithm>

intro_state *intro_state_instance = new intro_state();

std::string noche_text = "developed by noche";
std::string noche_text_o = noche_text;

void intro_state::create()
{
    srand(time(NULL));
    m_timer = new Stardust::Utilities::Timer();
    anim_timer = new Stardust::Utilities::Timer();
    m_timer->reset();
    anim_timer->reset();

    soulless_texture = Graphics::TextureUtil::LoadPng("assets/noche.png");

    soulless_sprite = new Graphics::Render2D::Sprite2(soulless_texture, {231, 47});
    soulless_sprite->position(240, 43);

    m_changing = false;
    noche_text_anim = new Graphics::UI::UIText({ 230, 200 }, "");
}

void intro_state::destroy()
{
    delete m_timer;
    delete anim_timer;

    delete soulless_texture;
    //delete noche_text_anim;

    delete soulless_sprite;
}

double easeOutCubic(double t)
{
    return 1 + (--t) * t * t;
}

double easeInOutExpo(double t)
{
    if (t < 0.5)
    {
        return (pow(2, 16 * t) - 1) / 510;
    }
    else
    {
        return 1 - 0.5 * pow(2, -16 * (t - 0.5));
    }
}

int alpha = 1;
float scale = 0.2f;
bool once = false;

void intro_state::render()
{
    if (soulless_texture == NULL || soulless_sprite == NULL)
        return;

    if (m_changing && !once) {
        g_state_manager.switch_to_next_state();
        once = true;
        return;
    }
    else if (m_changing && once)   
        return;


    anim_timer->deltaTime();
    m_timer->deltaTime();

    alpha = easeInOutExpo(anim_timer->elapsed() / 2) * 255;
    scale = easeOutCubic(anim_timer->elapsed() / 2) * 1.f;

    if (anim_timer->elapsed() > 2.0f)
    {
        alpha = 255;
        scale = 1.f;
    }
    if (m_timer->elapsed() > 2.4f && m_timer->elapsed() < 3.f)
         std::random_shuffle(noche_text_o.begin(), noche_text_o.end());
    if (m_timer->elapsed() > 3.f) {
        m_changing = true;
    }


    soulless_sprite->scale(scale, scale);
    soulless_sprite->setColor(0, 0, 0, alpha);
    soulless_sprite->draw();

    noche_text_anim->setContent(noche_text_o);
    Graphics::UI::FontStyle f;
	f.color = GU_RGBA(0, 0, 0, alpha);
	f.size = scale;
	f.options = INTRAFONT_ALIGN_CENTER;

    noche_text_anim->setOptions(f);
    noche_text_anim->draw();
}