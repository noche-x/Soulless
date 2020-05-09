#include "normal_enemy.h"

using namespace Stardust::Graphics::Render2D;

normal_enemy::normal_enemy(glm::vec2 spawn_pos, Graphics::Render2D::Tilemap *physics_tilemap, std::string texture_file)
{
    char_texture = Graphics::TextureUtil::LoadPng(texture_file);
    char_sprite = new Graphics::Render2D::CharacterSprite({50, 50}, new Graphics::TextureAtlas(4), char_texture);

    Graphics::Render2D::CharacterDirectionalAnimInfo *idle = new Graphics::Render2D::CharacterDirectionalAnimInfo();
    Graphics::Render2D::CharacterDirectionalAnimInfo *walk = new Graphics::Render2D::CharacterDirectionalAnimInfo();

    idle->down = {1, 1};
    idle->left = {5, 1};
    idle->right = {9, 1};
    idle->top = {13, 1};

    walk->down = {0, 4};
    walk->left = {4, 4};
    walk->right = {8, 4};
    walk->top = {12, 4};

    char_sprite->addAnimEvent("idle", idle);
    char_sprite->addAnimEvent("walk", walk);
    char_sprite->setDefaultAnimEvent("idle");
    char_sprite->triggerAnimEvent("idle");
    char_sprite->setFacing(Graphics::Render2D::CHARACTER_FACING_RIGHT);
    char_sprite->position(spawn_pos.x, spawn_pos.y);

    controller = new Graphics::Render2D::TopDownController(char_sprite, 13.0f);

    controller->addPhysicsTileMap(physics_tilemap);
    controller->getAnimController()->setCharacterTickRateRelative(12);
    controller->setPosition({500, 500});

	position = spawn_pos;

	ticksMovement = -1;

    ticksTilAction = rand() % 300;
    movement = {0, 0};
}

void normal_enemy::tick()
{
    ticksTilAction--;
    ticksMovement--;

    if (ticksTilAction <= 0)
    {
        handle_action(nextAction);

        ticksTilAction = rand() % 300;
        nextAction = rand() % 2;
    }
}

void normal_enemy::draw()
{
    controller->draw();
}

void normal_enemy::update()
{
    if (ticksMovement > 0)
    {
        controller->velocity = movement * 0.16f;
    }
    else
    {
        movement = {0, 0};
    }
    position = controller->getCharacterSprite()->getPosition();
    controller->update(0.16);
}

void normal_enemy::handle_action(int action)
{
    ticksMovement = rand() % 50 + 10;

    if (action == 1)
    {
        switch (controller->getCharacterSprite()->getFacing())
        {
        case CHARACTER_FACING_DOWN:
        {
            movement = {0.f, 64.f};
            break;
        }
        case CHARACTER_FACING_UP:
        {
            movement = {0.f, -64.f};
            break;
        }
        case CHARACTER_FACING_LEFT:
        {
            movement = {-64.f, 0.0f};
            break;
        }
        case CHARACTER_FACING_RIGHT:
        {
            movement = {64.f, 0.0f};
            break;
        }
        }

        controller->getCharacterSprite()->triggerAnimEvent("walk");
    }
    else
    {
        char dir = rand() % 4;
        controller->getCharacterSprite()->setFacing(dir);
    }
}