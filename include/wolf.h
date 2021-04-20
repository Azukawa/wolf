#ifndef WOLF_H
# define WOLF_H

# include "../SDL2-2.0.14/include/SDL.h"

# include "../libft/includes/libft.h"
# include "../ftprintf/includes/ft_printf.h"

# include <math.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_app
{
	SDL_Renderer	*renderer;
	SDL_Window		*window;
	SDL_Surface 	*screenSurface;
	SDL_Texture		*texture;
	char			*buffer;
	int				*tex;
	int				run;
	int				tex_pitch;
}					t_app;

typedef	struct		s_map
{
	char			**map;
	int				x;
	int				y;
}					t_map;

# define SCREEN_WIDTH 600
# define SCREEN_HEIGHT 400

void		ft_print2dcarr(char **arr);
char		*linetogrid(char *ret, char *out, int x);
int			readmap(char *str, t_map *s);
int			checkmap(char *str, t_map *s);
int			initmap(t_map *s);
int			buildmap(char *str, t_map *s);
void		initSDL(t_app *app);
void		cleanup(t_app *app);
void		drawmap(t_map *map, t_app *app);
void		drawpixel(float x, float y, char *buffer, int color);
#endif
