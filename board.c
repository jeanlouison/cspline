#include "board.h"
#include "point.h"

Board* _board = NULL;

void board_init();
uint8_t board_loop();
void board_clean();
void board_event();
void manage_keyboard_events(SDL_KeyboardEvent* event);
void manage_mouse_events(SDL_MouseButtonEvent* event);
void board_update_contents();
void board_draw();
void board_on_right_click(SDL_MouseButtonEvent* event);

Board* create_board(SDL_Window* window)
{
	Board* board = malloc(sizeof(Board));
	board->window = window;
    board->renderer = SDL_GetRenderer(window);
    board->board_init = &board_init;
    board->board_loop = &board_loop;
    board->board_clean = &board_clean;
    board->return_code = 1;
    _board = board;
    return board;
}

void board_init()
{
	SDL_SetRenderDrawColor(_board->renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(_board->renderer, NULL);
	SDL_RenderPresent(_board->renderer);
}

uint8_t board_loop()
{
    while(_board->return_code > 0) 
    {
        board_event();
        board_update_contents();
        board_draw();
    }
    return _board->return_code;
}

void board_clean()
{
    
}

void board_event()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_KEYDOWN:
				manage_keyboard_events(&(event.key));
				break;
			case SDL_MOUSEBUTTONDOWN:
				manage_mouse_events(&(event.button));
				break;
			case SDL_QUIT:
                _board->return_code = 0;
				break;
			default:
				break;
		}
	}
}

void manage_mouse_events(SDL_MouseButtonEvent* event)
{
	switch(event->button)
	{
		case(SDL_BUTTON_LEFT):
			switch(event->clicks)
			{
				case(1):
					board_on_right_click(event);
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
}

void manage_keyboard_events(SDL_KeyboardEvent* event)
{
    SDL_Keycode key = event->keysym.sym;
}

void board_update_contents()
{
	
}

void board_draw()
{
    //SDL_UpdateWindowSurface(_board->window);
    //SDL_RenderClear(_board->renderer);
    
    //SDL_SetRenderDrawColor(_board->renderer, 17, 17, 17, 255);

    //SDL_RenderPresent(_board->renderer);
}

void board_on_right_click(SDL_MouseButtonEvent* event)
{
	SDL_UpdateWindowSurface(_board->window);
    SDL_RenderClear(_board->renderer);
    SDL_SetRenderDrawColor(_board->renderer, 17, 17, 17, 255);
	Point* point = create_point(event->x, event->y);
	draw_point(_board->renderer, point);
	SDL_SetRenderDrawColor(_board->renderer, 0, 0, 0, 255);
	SDL_RenderPresent(_board->renderer);
}