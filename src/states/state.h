#pragma once 

#include <Graphics/RendererCore.h>
#include <Graphics/UI/UIBase.h>
#include <Graphics/UI/UIText.h>
#include <Graphics/UI/UIButton.h>

using namespace Stardust;

class state
{
private:
    /* data */
    state* m_next_state;
public:
    virtual void create() = 0;
    virtual void destroy() = 0;
    
    virtual void render() = 0;
};