#ifndef BOARD_H
#define BOARD_H

#include <SDL2/SDL.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct Board {
    SDL_Window* window;
    SDL_Renderer* renderer;
    void (*board_init)();
    uint8_t (*board_loop)();
    void (*board_clean)();
    uint8_t return_code;
} Board;

Board* create_board(SDL_Window* window);

//Point* create_point(int32_t pos_x, int32_t pos_y);
//void draw_point(SDL_Renderer* renderer, Point* point);
//void clean_point(Point** point);

#endif // BOARD_H