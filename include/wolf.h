#ifndef WOLF_H
# define WOLF_H

# include "../SDL2-2.0.14/include/SDL.h"

# include "libft.h"
# include "ft_gfx.h"

# include <time.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		angle;
	int			fov;
	double		move_u;
	double		rotation_u;
}				t_player;

typedef struct s_raycaster
{
	double		ray_angle;
	double		raycast_unit;
	int			precision;
	double		ray_cos;
	double		ray_sin;
}				t_raycaster;

typedef struct s_app
{
	SDL_Renderer	*renderer;
	SDL_Window		*window;
	SDL_Surface		*screenSurface;
	SDL_Texture		*texture;
	uint32_t		*buffer;
	uint32_t		*tex;
	t_player		player;
	t_raycaster		rc;
	int				run;
	int				tex_pitch;
	t_bool			draw_ui;
}					t_app;

typedef struct s_map
{
	char			**map;
	int				w;
	int				h;
}					t_map;

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_fpoint
{
	float			x;
	float			y;
}					t_fpoint;

typedef struct s_map_player
{
	t_fpoint		p;
	float			dir;
}					t_map_player;

# define WOLF_HEADER "Wolf3d by esukava & eniini"

# define SCREEN_WIDTH 600
# define SCREEN_HEIGHT 400

# define HALF_SW 300
# define HALF_SH 200

void		ft_print2dcarr(char **arr);
char		*linetogrid(char *ret, char *out, int x);
int			readmap(char *str, t_map *s);
int			checkmap(char *str, t_map *s);
int			initmap(t_map *s);
int			buildmap(char *str, t_map *s);

void		init_SDL(t_app *app);
void		init_player_vars(t_app *app);

void		cleanup(t_app *app);
void		drawmap(t_map *map, t_app *app);

void		drawpixel(int x, int y, uint32_t *buffer, uint32_t color);

void		draw_line(t_app *wolf, t_point p0, t_point p1, int color);
void		draw_circle(t_app *wolf, t_point p, int r, int color);
void		draw_filled_circle(t_app *wolf, t_point p, int r, int color);

void		raycast(t_app *app, t_map *map);

void		keyevent(t_app *app, SDL_Event *e, t_map_player *p, t_map *map);
void		drawplayer(t_app *app, t_map_player *player, t_map *map);

void		fps_counter(void);
uint32_t	argb_grayscale(uint32_t c);
uint32_t	argb_realgrayscale(uint32_t c);

#endif
