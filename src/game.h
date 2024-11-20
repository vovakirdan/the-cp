#ifndef GAME_H
#define GAME_H

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define TILE_SIZE 32   // Size of one tile (32x32 pixels)
#define MAP_WIDTH 25   // Number of tiles horizontally
#define MAP_HEIGHT 19  // Number of tiles vertically

typedef struct {
    int x, y;  // Player position in tiles
} Player;

#endif // GAME_H
