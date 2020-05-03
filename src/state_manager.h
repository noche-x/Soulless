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
public:
    state_manager();

    void set_state(state* state);    

    void render_state();

    ~state_manager();
};
