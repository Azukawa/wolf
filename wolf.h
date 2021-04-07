#ifndef WOLF_H
# define WOLF_H

#include "SDL2-2.0.14/include/SDL.h"

typedef struct s_app {
	SDL_Renderer	*renderer;
	SDL_Window		*window;
	SDL_Surface 	*screenSurface;
		} t_app;

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#endif
