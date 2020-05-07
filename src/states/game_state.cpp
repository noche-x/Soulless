#include "game_state.h"
#include "../menu_system/menu_system.h"
#include "../state_manager.h"

game_state* game_state_instance = new game_state();

void game_state::create() {
    g_menu_system.~menu_system();
    Stardust::Utilities::clearActionHandlers();
    Stardust::Utilities::clearActionKeyPairs();

    textures = Graphics::TextureUtil::LoadPng("assets/texture_atlas.png");
	texture_atlas = new Graphics::TextureAtlas(16);

    texture_tilemap = new Graphics::Render2D::Tilemap(texture_atlas, textures);
    texture_tilemap->loadTileFromJSON("assets/map.json");
	texture_tilemap->buildMap();

	char_texture = Graphics::TextureUtil::LoadPng("assets/ghost.png");
	char_sprite = new Graphics::Render2D::CharacterSprite({ 32, 32 }, new Graphics::TextureAtlas(1), char_texture);

	Graphics::Render2D::CharacterDirectionalAnimInfo* idle = new Graphics::Render2D::CharacterDirectionalAnimInfo();
	
	idle->down = { 1, 1 };
	idle->left = { 5, 1 };
	idle->right = { 9, 1 };
	idle->top = { 13,1 };

	char_sprite->addAnimEvent("idle", idle);
	char_sprite->setDefaultAnimEvent("idle");
	char_sprite->triggerAnimEvent("idle");
	char_sprite->setFacing(Graphics::Render2D::CHARACTER_FACING_DOWN);
	char_sprite->position(7, 7);

	controller = new Graphics::Render2D::TopDownController(char_sprite, 128.0f);

	Utilities::addActionKeyPair("walkUp", PSP_CTRL_UP);
	Utilities::addActionKeyPair("walkDown", PSP_CTRL_DOWN);
	Utilities::addActionKeyPair("walkLeft", PSP_CTRL_LEFT);
	Utilities::addActionKeyPair("walkRight", PSP_CTRL_RIGHT);

	controller->getAnimController()->setCharacterTickRateRelative(24);
	controller->setPosition({ 220,220 });

	controller->registerHandlers();
}

void game_state::destroy() {
    delete textures;
    delete texture_atlas;

    delete texture_tilemap;
}

void game_state::render() {    
    texture_tilemap->drawMap();

    controller->draw();
}