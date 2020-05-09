#pragma once 

#include <Graphics/RendererCore.h>
#include <Graphics/UI/UIBase.h>
#include <Graphics/UI/UIText.h>
#include <Graphics/UI/UIButton.h>

#include "states/state.h"

using namespace Stardust;

class state_manager
{
private:
    /* data */
    std::vector<state*> m_states;
    state* m_active_state;
    state* m_next_state;
    state* m_next_alt_state;
public:
    state_manager();

    void set_state(state* state);    

    void set_next_state(state* state);
    void set_next_alt_state(state* state);

    void render_state();
    state* get_state();

    void switch_to_next_state();
    void switch_to_next_alt_state();

    ~state_manager();
};

extern state_manager g_state_manager;