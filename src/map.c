#include "map.h"
#include "game.h"
#include <stdlib.h>

// Generate a random map
void generateMap(int map[MAP_HEIGHT][MAP_WIDTH]) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            // Simple logic: ground (1) for the bottom 4 rows, empty space (0) above
            if (y >= MAP_HEIGHT - 4) {
                map[y][x] = 1;  // Ground tile
            } else {
                map[y][x] = 0;  // Empty space
            }
        }
    }
}

// Render the map
void renderMap(SDL_Renderer* renderer, int map[MAP_HEIGHT][MAP_WIDTH]) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (map[y][x] == 1) {
                // Set color for ground tiles
                SDL_SetRenderDrawColor(renderer, 139, 69, 19, 255); // Brown
            } else {
                // Set color for empty tiles
                SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255); // Sky blue
            }
            
            SDL_Rect tile = { x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE };
            SDL_RenderFillRect(renderer, &tile);
        }
    }
}
