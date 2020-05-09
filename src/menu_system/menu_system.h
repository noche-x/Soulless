#pragma once

#include <Utilities/Input.h>
#include <Graphics/UI/UIButton.h>
#include <map>

struct key_set {
    int up_key;
    int down_key;
    int left_key;
    int right_key;
    int select_key;
    int exit_key;
};

class menu_system
{
private:
    /* data */
    static menu_system static_instance;

    key_set current_key_set;
    int button_count;
    int selected_button;
	std::map<int, Stardust::Graphics::UI::UIButton*> buttons;

    static void menu_up(bool held, float strength);
    static void menu_down(bool held, float strength);
    static void menu_left(bool held, float strength);
    static void menu_right(bool held, float strength);
    static void menu_select(bool held, float strength);
    static void menu_exit(bool held, float strength);    
public:
    menu_system();
    ~menu_system();

    static menu_system& get() {
        return static_instance;
    }

    void set_key_set(key_set keys);
    void set_default_key_set();
    void set_button_action(int i, Stardust::Graphics::UI::ClickAction act);
    void add_button(Stardust::Graphics::UI::UIButton *button);

    void update();
};

extern menu_system g_menu_system;
