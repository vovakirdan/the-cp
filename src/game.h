#ifndef GAME_H
#define GAME_H

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define TILE_SIZE 32   // Size of one tile (32x32 pixels)
#define MAP_WIDTH 25   // Number of tiles horizontally
#define MAP_HEIGHT 19  // Number of tiles vertically

#define PLAYER_SPEED 5  // Player movement speed
#define JUMP_FORCE 12 
#define GRAVITY 1

typedef struct {
    Uint8 r, g, b, a;
} Color;

static const Color COLOR_SKY = {135, 206, 235, 255};
static const Color COLOR_GROUND = {139, 69, 19, 255};
static const Color COLOR_PLAYER = {255, 0, 0, 255}; // red

// player struct
typedef struct {
    float x, y;  // Player position in pixels
    float dx, dy;  // Player movement speed
    int width, height;  // Player size
    int onGround;  // Is the player on the ground?
} Player;

// function declarations
void handlePlayerInput(Player *player);
void updatePlayer(Player *player, int map[MAP_HEIGHT][MAP_WIDTH]);
void renderPlayer(SDL_Renderer* renderer, Player *player);

#endif // GAME_H
