#include "menu_system.h"
#include <Utilities/Logger.h>

menu_system g_menu_system;

menu_system menu_system::static_instance;

void menu_system::menu_up(bool held, float strength) {
    get().selected_button--;
    sceKernelDelayThread(100000);
    Stardust::Utilities::app_Logger->log("menu up");
}

void menu_system::menu_down(bool held, float strength) {
    get().selected_button++;
    sceKernelDelayThread(100000);
    Stardust::Utilities::app_Logger->log("menu down");
}

void menu_system::menu_left(bool held, float strength) {
    
}

void menu_system::menu_right(bool held, float strength) {

}

void menu_system::menu_select(bool held, float strength) {
    get().buttons[get().selected_button]->click();
}

void menu_system::menu_exit(bool held, float strength) {

}

void menu_system::set_button_action(int i, Stardust::Graphics::UI::ClickAction act) {
    get().buttons[i]->setClickAction(act);
}

void menu_system::update() {
    if (get().selected_button > this->button_count)
        get().selected_button = 1;
    else if (get().selected_button <= 0)
        get().selected_button = this->button_count;


    for (int i = 1; i <= this->button_count; i++) {
        get().buttons[i]->setUnselected();
        if (i == get().selected_button)
            get().buttons[i]->setSelected();
        get().buttons[i]->draw();        
    }
}

void menu_system::add_button(Stardust::Graphics::UI::UIButton* button) {
    this->button_count++;
    get().buttons.emplace(this->button_count, button);
}

void menu_system::set_default_key_set() {
    key_set set;
    set.up_key = PSP_CTRL_UP;
    set.down_key = PSP_CTRL_DOWN;
    set.left_key = PSP_CTRL_LEFT;
    set.right_key = PSP_CTRL_RIGHT;
    set.select_key = PSP_CTRL_CROSS;
    set.exit_key = PSP_CTRL_CIRCLE;

    this->set_key_set(set);
}

menu_system::menu_system() {
    this->button_count = 0;
    this->selected_button = 1;
    this->set_default_key_set();
    this->buttons = {};
    get().buttons = {};

    Stardust::Utilities::addActionHandler("menu_up", this->menu_up);
    Stardust::Utilities::addActionHandler("menu_down", this->menu_down);
    Stardust::Utilities::addActionHandler("menu_left", this->menu_left);
    Stardust::Utilities::addActionHandler("menu_right", this->menu_right);
    Stardust::Utilities::addActionHandler("menu_select", this->menu_select);
    Stardust::Utilities::addActionHandler("menu_exit", this->menu_exit);
}

menu_system::~menu_system() {
    Stardust::Utilities::clearActionHandlers();
    Stardust::Utilities::clearActionKeyPairs();
}

void menu_system::set_key_set(key_set keys) {
    Stardust::Utilities::clearActionKeyPairs();
    this->current_key_set = keys;

    Stardust::Utilities::setActionKeyPair("menu_up", this->current_key_set.up_key);
    Stardust::Utilities::setActionKeyPair("menu_down", this->current_key_set.down_key);
    Stardust::Utilities::setActionKeyPair("menu_left", this->current_key_set.left_key);
    Stardust::Utilities::setActionKeyPair("menu_right", this->current_key_set.right_key);
    Stardust::Utilities::setActionKeyPair("menu_select", this->current_key_set.select_key);
    Stardust::Utilities::setActionKeyPair("menu_exit", this->current_key_set.exit_key);
}