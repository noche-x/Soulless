#pragma once
#include <Graphics/2D/SpriteBase.h>
#include <Graphics/2D/CharacterSprite.h>
#include <Graphics/2D/TopDownController.h>

class enemy {
public:
    virtual void draw() = 0;
    virtual void update() = 0;

    glm::vec2 get_position() {
        return position;
    }

	Stardust::Graphics::Texture* texture;
	Stardust::Graphics::Render2D::CharacterSprite* sprite;
	Stardust::Graphics::Render2D::TopDownController* controller;

	int ticksTilAction;
	char nextAction;

	int ticksMovement;

	glm::vec2 movement;
    
	glm::vec2 position;
};