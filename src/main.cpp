#include <Platform/Platform.h>
#include <pspkernel.h>
#include <pspdebug.h>
#include <pspmath.h>
#include <iostream>

PSP_MODULE_INFO("Soulless", 0, 0, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_VFPU | THREAD_ATTR_USER);
PSP_HEAP_SIZE_KB(-1024);

#define MC_PSP
#include <Utilities/Timer.h>
#include <Utilities/Logger.h>
#include <Utilities/Input.h>
#include <Graphics/Dialogs.h>
#include <Graphics/RendererCore.h>
#include <Graphics/UI/UIBase.h>
#include <Graphics/UI/UIText.h>
#include <Graphics/UI/UIButton.h>

using namespace Stardust;

int main() {
    Platform::initPlatform("Soulless");

    // assets
    auto non_selected_button_texture = Graphics::TextureUtil::LoadPng("assets/non_selected.png");
    auto selected_button_texture = Graphics::TextureUtil::LoadPng("assets/selected.png");

    // graphics
    Stardust::Graphics::UI::UIText* play_text = new Stardust::Graphics::UI::UIText({ 240, 136 }, "play");
    Stardust::Graphics::UI::UIButton* start_button = new Stardust::Graphics::UI::UIButton({25, 25}, {100, 25}, non_selected_button_texture, selected_button_texture, play_text);

    Graphics::g_RenderCore.Set2DMode();    
    while (true) {
        Graphics::g_RenderCore.BeginCommands();
        Graphics::g_RenderCore.Clear();
        //Draw
        play_text->draw();
        start_button->setPosition({240, 136});
        start_button->draw();

        Platform::platformUpdate();
        Graphics::g_RenderCore.EndCommands();
    }


    Platform::exitPlatform();
    return 0;
}