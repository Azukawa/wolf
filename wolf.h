#ifndef WOLF_H
# define WOLF_H

#include "libSDL2/include/SDL2/SDL.h"

typedef struct s_app {
	SDL_Renderer	*renderer;
	SDL_Window	*window;
		} t_app;

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#endif