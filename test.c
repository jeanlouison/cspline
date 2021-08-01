#include <stdio.h>
#include <SDL2/SDL.h>
#include <time.h>

#include "point.h"
#include "board.h"

Board* _main_board = NULL;

int init();
int main(int argc, char* argv[]);

int init()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("Test", 32, 32, 640, 480, SDL_WINDOW_RESIZABLE);
	
	if (window == NULL)
	{
		printf("erreur init window %s\n", SDL_GetError());
		return 1;
	}
	
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	
	if (renderer == NULL)
	{
		printf("erreur init renderer %s\n", SDL_GetError());
		return 1;
	}
	
	_main_board = create_board(window);
	_main_board->board_init();
	
	return 0;
}

int main (int argc, char* argv[]) 
{
	init();
	int status = 1;
	while(status)
	{
		status = _main_board->board_loop();
		//update();
	}
	_main_board->board_clean();
	
	SDL_Quit();
	
	return 0;
}