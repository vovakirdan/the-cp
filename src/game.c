#include <SDL2/SDL.h>
#include "game.h"

// handle player input
void handlePlayerInput(Player* player) {
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    if (keystate[SDL_SCANCODE_LEFT]) {
        player->dx = -PLAYER_SPEED;
    } else if (keystate[SDL_SCANCODE_RIGHT]) {
        player->dx = PLAYER_SPEED;
    } else {
        player->dx = 0;
    }

    if (keystate[SDL_SCANCODE_SPACE] && player->onGround) {
        player->dy = -JUMP_FORCE;
        player->onGround = 0;
    }
}

// update player position and handle collisions
void updatePlayer(Player* player, int map[MAP_HEIGHT][MAP_WIDTH]) {
    // apply gravity
    player->dy += GRAVITY;

    // calculate next position
    float nextX = player->x + player->dx;
    float nextY = player->y + player->dy;

    // tile-based collision detection
    int leftTile = (int)(nextX / TILE_SIZE);
    int rightTile = (int)((nextX + player->width) / TILE_SIZE);
    int topTile = (int)(nextY / TILE_SIZE);
    int bottomTile = (int)((nextY + player->height) / TILE_SIZE);

    // horizontal collision
    if (player->dx > 0 && map[(int)(player->y / TILE_SIZE)][rightTile] == 1) {
        nextX = rightTile * TILE_SIZE - player->width;
        player->dx = 0;
    } else if (player->dx < 0 && map[(int)(player->y / TILE_SIZE)][leftTile] == 1) {
        nextX = (leftTile + 1) * TILE_SIZE;
        player->dx = 0;
    }

    // vertical collision
    if (player->dy > 0 && map[bottomTile][(int)(player->x / TILE_SIZE)] == 1) {
        nextY = bottomTile * TILE_SIZE - player->height;
        player->dy = 0;
        player->onGround = 1;
    } else if (player->dy < 0 && map[topTile][(int)(player->x / TILE_SIZE)] == 1) {
        nextY = (topTile + 1) * TILE_SIZE;
        player->dy = 0;
    }

    // update player position
    player->x = nextX;
    player->y = nextY;
}

// render player
void renderPlayer(SDL_Renderer* renderer, Player* player) {
    SDL_SetRenderDrawColor(renderer, COLOR_PLAYER.r, COLOR_PLAYER.g, COLOR_PLAYER.b, COLOR_PLAYER.a);
    SDL_Rect rect = {(int)player->x, (int)player->y, player->width, player->height};
    SDL_RenderFillRect(renderer, &rect);

    //todo render player's hitbox (for debugging purposes)
}