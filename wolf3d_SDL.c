//#include "SDL/include/SDL.h"
#include "wolf.h"

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
		ft_printf("row%d =\t\t%s\n", i, arr[i]);
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
//	free(output);
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
		if(ft_wordcount(output, ',') > (size_t)s->x)
			s->x = ft_wordcount(output, ',');
		i++;
		free(output);
	}
	s->y = i;
//	free(output);
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
		ft_printf("No path given, map building is skipped.\n");
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
	app->buffer = ft_memalloc(SCREEN_WIDTH * SCREEN_HEIGHT * 4);
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		exit(ft_printf("couldn't initialize SDL: %s\n", SDL_GetError()));
	if (!(app->window = SDL_CreateWindow("Testgame01", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags)))
		exit(ft_printf("failed to open %d x %d window %s\n", SCREEN_WIDTH,
		SCREEN_HEIGHT, SDL_GetError()));
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	if (!(app->renderer = SDL_CreateRenderer(app->window, -1, renderFlags)))
		exit(ft_printf("Failed to create renderer: %s\n", SDL_GetError()));
	if(!(app->texture = SDL_CreateTexture(app->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT)))
		exit(ft_printf("Failed to create texture: %s\n", SDL_GetError()));

}

/*void			free2darr(t_map *map)
{
	int y;
	y = 0;
	while(y < map->y)
	{
		free(map->map[y]);
		y++;
	}
	free(map->map);
}*/

void	cleanup(t_app *app)
{
	SDL_DestroyRenderer(app->renderer);
	SDL_DestroyWindow(app->window);
}

//todo check if color should be unsigned int
//todo check endian for correct colors
void		drawpix2buf(float x, float y, char *buffer, int color)
{
	int	i;
	i = ((int)x + SCREEN_WIDTH * (int)y) * 4;
	if (x < SCREEN_WIDTH && y < SCREEN_HEIGHT &&  x >= 0 && y >= 0)
	{
		buffer[0 + i] = (color >> 24);
		buffer[1 + i] = (color) & 0xFF;
		buffer[2 + i] = (color >> 8) & 0xFF;
		buffer[3 + i] = (color >> 16) & 0xFF;
	}
}


void		drawmap(t_map *map, t_app *app)
{	
	if (map->x == 0 || map->y == 0)
		return ;
	int	x, y, square_x, square_y;
	x = y = 0;
	square_x = SCREEN_WIDTH / map->x;
	square_y = SCREEN_HEIGHT / map->y;
	printf("mapx=%d\nmapy=%d\n", map->x, map->y);
	while(y < SCREEN_HEIGHT)
	{	
		while(x < SCREEN_WIDTH)
		{
			if (map->map[y / square_y][ x / square_x] == '0')
				drawpix2buf(x, y, app->buffer, 0xFFFFFF);
			else
				drawpix2buf(x, y, app->buffer, 0x000000);
			x++;
		}
		x = 0;
		y++;
	}
}

int			main(int argc, char** argv)
{
	t_map		*s;
	t_app		*app;

	if (argc != 2)
		ft_printf("Wrong number of arguments.\n");
	s = ft_memalloc(sizeof(app));
	app = ft_memalloc(sizeof(app));
	app->run = 1;
	ft_memset(app, 0, sizeof(app));
	ft_memset(s, 0, sizeof(s));
	initSDL(app);
	ft_printf("xxx\n");
	buildmap(argv[1], s);
	ft_printf("yyy\n");
	ft_print2dcarr(s->map);
	ft_printf("zzz\n");
	app->screenSurface = SDL_GetWindowSurface(app->window);
		while(app->run)
		{
			drawmap(s, app);
			if(SDL_LockTexture(app->texture, NULL, (void **)&app->tex, &app->tex_pitch) < 0)
				app->run = 0;
			ft_memcpy(app->tex, app->buffer, SCREEN_HEIGHT * SCREEN_WIDTH * 4);
			SDL_UnlockTexture(app->texture);
			if (SDL_RenderCopy(app->renderer, app->texture, NULL, NULL) < 0)
				app->run = 0;
			SDL_RenderPresent(app->renderer);		
			app->run = 0;
		}
	ft_printf("111\n");
	SDL_RenderPresent(app->renderer);
	SDL_Delay(3000);
	ft_printf("2222\n");
	cleanup(app);

	//ft_free_arr(s->map);
	free(s);
	free(app);

	printf("3333\n");
	//SDL_DestroyWindow(app->window);
	printf("Ran untill end\n");
	return (1);
}
