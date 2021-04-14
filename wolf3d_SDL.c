//#include "SDL/include/SDL.h"
#include "wolf.h"

#include "Libft/inc/libft.h"
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>

typedef	struct			s_map
{
	char	**map;
	int		x;
	int		y;
}						t_map;

/*
 *	Simple 2d char array printer using prinf
 */
void	ft_print2dcarr(char **arr)
{
	int i;
	i = 0;
	if (!arr)
		return ;
	while(arr[i][0] != '\0')
	{
		printf("row%d =\t\t%s\n", i, arr[i]);
		i++;
	}
}

/*
 *	Skips ',' and ' ' characters,
 *	puts rest to ret, up to x(max widht of map)
 */
char	*linetogrid(char *ret, char *out, int x)
{
	int a;
	int i;

	i = 0;
	a = 0;
	if(ret == NULL || out == NULL)
		return(0);
	while (i < x && out[a != '\0'])
	{
		if(out[a] != ',' && out[a] != ' ' )
		{
			ret[i] = out[a];
			i++;
		}
		a++;
	}
	ret[i] = '\0';
	return(ret);
}

/*
 *	The second redthrough of map file.
 *	Goes through file line by line,
 *	and builds final array with
 *	linetogrid()
 */
int			readmap(char *str, t_map *s)
{
	int		fd;
	int		ret;
	int		i;
	char*	output;

	i = 0;
	
	if ((fd = open(str, O_RDONLY)) == -1)
		return(0);
	while ((ret = get_next_line(fd, &output)) > 0)
	{
		s->map[i] = linetogrid(s->map[i], output, s->x);
		i++;
		free(output);
	}
	free(output);
	return(1);

}

/*
 *	The first read of map file.
 *	This function determines map.x and map.y.
 *	Y rows are counted by gnl,
 *	X is counted by the nro ',' on the row.
 */
int		checkmap(char *str, t_map *s)
{
	int		fd;
	int		ret;
	int		i;
	char*	output;

	i = 0;
	output = NULL;
	
	if ((fd = open(str, O_RDONLY)) == -1)
		return(0);
	while ((ret = get_next_line(fd, &output)) > 0)
	{
		if(ft_countwords(output, ',') > s->x)
			s->x = ft_countwords(output, ',');
		i++;
		free(output);
	}
	s->y = i;
	free(output);
	return (0);
}

/*
 *	Allocates 2d character array,
 *	based  on map.x and map.y.
 *	Each row is zeroed,
 *	terminators are placed.
 */
int		initmap(t_map *s)
{
	int i;
	i = 0;
	s->map = (char **)malloc(sizeof(char *) * s->y);
	while(i <= s->y)
	{
		s->map[i] = (char *)malloc(sizeof(char *) * s->x);
		ft_bzero(s->map[i], s->x);
		s->map[i][s->x] = '\0';
		i++;
	}
	s->map[s->y][0] = '\0';
//	ft_memset(s->map, 0, sizeof(char *) * s->y * s->x);
	ft_strclr(s->map[s->y]);
	return(0);
}

/*
 *	Simple mother function for
 *	commanding the seperate map
 *	reading functions.
 *	final 2d char will be map[y][x]
 */
int			buildmap(char *str, t_map *s)
{	
	if (str == NULL)
	{
		printf("No path given, map building is skipped.\n");
		return(0);
	}
	checkmap(str, s);
	initmap(s);
	readmap(str, s);
	return (1);
}

void	initSDL(t_app *app)
{
	int		renderFlags = SDL_RENDERER_ACCELERATED;
	int		windowFlags = 0;
	app->window = NULL;
	app->screenSurface = NULL;
	app->renderer = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		exit(printf("XXXXXcouldn't initialize SDL: %s\n", SDL_GetError()));
	if (!(app->window = SDL_CreateWindow("Testgame01", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags)))
		exit(printf("failed to open %d x %d window %s\n", SCREEN_WIDTH,
		SCREEN_HEIGHT, SDL_GetError()));
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	if (!(app->renderer = SDL_CreateRenderer(app->window, -1, renderFlags)))
		exit(printf("Failed to create renderer: %s\n", SDL_GetError()));
}

void			free2darr(t_map *map)
{
	int y;
	y = 0;
	while(y < map->y)
	{
		free(map->map[y]);
		y++;
	}
	free(map->map);
}

void	cleanup(t_app *app)
{
	printf("555, %p\n", app->renderer);
	SDL_DestroyRenderer(app->renderer);
	printf("666\n");
	SDL_DestroyWindow(app->window);
	printf("777\n");
}

void		drawmap(t_map *map, t_app *app)
{	
	if (map->x == 0 || map->y == 0)
		return ;
	int	x, y, square_x, square_y;
	x = y = 0;
	square_x = SCREEN_WIDTH / map->x;
	square_y = SCREEN_HEIGHT / map->y;
	SDL_SetRenderDrawColor(app->renderer, 0, 0, 0, 0);
	SDL_RenderClear(app->renderer);
	SDL_SetRenderDrawColor(app->renderer, 255, 0, 0, 255);
	printf("mapx=%d\nmapy=%d\n", map->x, map->y);
	while(y < SCREEN_HEIGHT)
	{	
		while(x < SCREEN_WIDTH)
		{
			if (map->map[y / square_y][ x / square_x] == '0')
				SDL_SetRenderDrawColor(app->renderer, 255, 255, 255, 255);
			else
				SDL_SetRenderDrawColor(app->renderer, 0, 0, 0, 0);
			SDL_RenderDrawPoint(app->renderer, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

int			main(int argc, char** argv)
{
	t_map		s;
	t_app		app;

	if (argc != 2)
		printf("Wrong number of arguments.\n");
	ft_memset(&app, 0, sizeof(app));
	ft_memset(&s, 0, sizeof(s));
	initSDL(&app);
	printf("xxx\n");
	buildmap(argv[1], &s);
	printf("yyy\n");
	ft_print2dcarr(s.map);
	printf("zzz\n");
	app.screenSurface = SDL_GetWindowSurface(app.window);
	drawmap(&s, &app);
	printf("111\n");
	SDL_RenderPresent(app.renderer);
	SDL_Delay(3000);
	printf("2222\n");
//	free2darr(&s);
//	int i = 0;
//	while(i < s.y)
//		free(s.map[i++]);
//	free(s.map);
//	cleanup(&app);
	printf("3333\n");
	SDL_DestroyWindow(app.window);
	printf("Ran untill end\n");
	return (1);
}
