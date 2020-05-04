#include <Platform/Platform.h>
#include <pspkernel.h>
#include <pspdebug.h>
#include <pspmath.h>
#include <iostream>
#include <memory>

PSP_MODULE_INFO("Soulless", 0, 0, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_VFPU | THREAD_ATTR_USER);
PSP_HEAP_SIZE_KB(-1024);

#include <Utilities/Timer.h>
#include <Utilities/Logger.h>
#include <Utilities/Input.h>
#include <Graphics/Dialogs.h>
#include <Graphics/RendererCore.h>
#include <Graphics/UI/UIBase.h>
#include <Graphics/UI/UIText.h>
#include <Graphics/UI/UIButton.h>

#include "state_manager.h"
#include "states/main_menu_state.h"

using namespace Stardust;

int main() {
    Platform::initPlatform("Soulless");

    state_manager g_state_manager;
    
    main_menu_state* main_menu_state_instance = new main_menu_state();
    main_menu_state_instance->create();

    g_state_manager.set_state(main_menu_state_instance);

    Graphics::g_RenderCore.SetClearColor(160, 160, 160, 255);
    
    Graphics::g_RenderCore.Set2DMode();    
    while (true) {
        Graphics::g_RenderCore.BeginCommands();
        Graphics::g_RenderCore.Clear();

        g_state_manager.render_state();  

        Platform::platformUpdate();
        Graphics::g_RenderCore.EndCommands();
    }


    Platform::exitPlatform();
    return 0;
}