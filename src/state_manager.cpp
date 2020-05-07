#include "state_manager.h"

state_manager g_state_manager;

state_manager::state_manager(/* args */)
{
}

state_manager::~state_manager()
{
}

void state_manager::set_state(state* state) {
    m_active_state = state;
    state->create();
}

void state_manager::set_next_state(state* state) {
    m_next_state = state;
}

void state_manager::render_state() {
    m_active_state->render();
}

void state_manager::switch_to_next_state() {
    m_active_state->destroy();
    set_state(this->m_next_state);
}