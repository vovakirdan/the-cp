#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>
#include "game.h"

// Function declarations
void generateMap(int map[MAP_HEIGHT][MAP_WIDTH]);
void renderMap(SDL_Renderer* renderer, int map[MAP_HEIGHT][MAP_WIDTH]);

#endif // MAP_H
