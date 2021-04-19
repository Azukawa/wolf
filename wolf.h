#ifndef WOLF_H
# define WOLF_H

# include "SDL2-2.0.14/include/SDL.h"

# include "libft/includes/libft.h"
# include "ftprintf/includes/ft_printf.h"

# include <math.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_app
{
	SDL_Renderer	*renderer;
	SDL_Window		*window;
	SDL_Surface 	*screenSurface;
}					t_app;

typedef	struct		s_map
{
	char			**map;
	int				x;
	int				y;
}					t_map;

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

#endif
