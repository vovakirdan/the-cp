#include <SDL2/SDL.h>
#include "game.h"
#include "map.h"

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("2D Platformer", 
                                          SDL_WINDOWPOS_CENTERED, 
                                          SDL_WINDOWPOS_CENTERED, 
                                          SCREEN_WIDTH, SCREEN_HEIGHT, 
                                          SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Game variables
    int map[MAP_HEIGHT][MAP_WIDTH];
    generateMap(map);

    Player player = {
        .x = TILE_SIZE * 5,
        .y = TILE_SIZE * 5,
        .dx = 0,
        .dy = 0,
        .width = TILE_SIZE,
        .height = TILE_SIZE,
        .onGround = 0
    };

    // Timing
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    // Game loop
    int running = 1;
    SDL_Event e;
    while (running) {
        frameStart = SDL_GetTicks();

        // Handle events
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                running = 0;
            }
        }

        // Handle input
        handlePlayerInput(&player);

        // Update game state
        updatePlayer(&player, map);

        // Render
        SDL_SetRenderDrawColor(renderer, COLOR_SKY.r, COLOR_SKY.g, COLOR_SKY.b, COLOR_SKY.a); // Sky background
        SDL_RenderClear(renderer);

        renderMap(renderer, map);
        renderPlayer(renderer, &player);

        SDL_RenderPresent(renderer);

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
