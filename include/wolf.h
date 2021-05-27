#ifndef WOLF_H
# define WOLF_H

# include "../SDL2-2.0.14/include/SDL.h"

# include "libft.h"
# include "ft_gfx.h"

# include <math.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_app
{
	SDL_Renderer	*renderer;
	SDL_Window		*window;
	SDL_Surface 	*screenSurface;
	SDL_Texture		*texture;
	uint32_t		*buffer;
	uint32_t		*tex;
	int				run;
	int				tex_pitch;
}					t_app;

typedef	struct		s_map
{
	char			**map;
	int				w;
	int				h;
}					t_map;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_fpoint
{
	float			x;
	float			y;
}					t_fpoint;

typedef struct		s_player
{
	t_fpoint		p;
	float			dir;
}					t_player;

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
void		drawpixel(int x, int y, uint32_t *buffer, int color);

void		draw_line(t_app *wolf, t_point p0, t_point p1, int color);
void		draw_circle(t_app *wolf, t_point p, int r, int color);
void		draw_filled_circle(t_app *wolf, t_point p, int r, int color);
void		keyevent(t_app *app, SDL_Event *e, t_player *p);
void		drawplayer(t_app *app, t_player *player);
#endif
