#include "state_manager.h"

state_manager::state_manager(/* args */)
{
}

state_manager::~state_manager()
{
}

void state_manager::set_state(state* state) {
    m_states.push_back(state);
}

void state_manager::render_state() {
    m_states.back()->render();
}