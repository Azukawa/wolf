//#include "SDL/include/SDL.h"
#include "wolf.h"

#include "Libft/inc/libft.h"
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>

typedef	struct			s_struct
{
	char	**map;
	int		x;
	int		y;
}						t_struct;

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
	return(ret);
}

/*
 *	The second redthrough of map file.
 *	Goes through file line by line,
 *	and builds final array with
 *	linetogrid()
 */
int			readmap(char *str, t_struct *s)
{
	int		fd;
	int		ret;
	int		i;
	char*	output;


	
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
int		checkmap(char *str, t_struct *s)
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
int		initmap(t_struct *s)
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
	ft_strclr(s->map[s->y]);
	return(0);
}

/*
 *	Simple mother function for
 *	commanding the seperate map
 *	reading functions.
 */
int			buildmap(char *str, t_struct *s)
{
	checkmap(str, s);
	initmap(s);
	readmap(str, s);
	return (0);
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

void	cleanup(t_app *app)
{
	SDL_DestroyRenderer(app->renderer);
	
	SDL_DestroyWindow(app->window);

	SDL_Quit();
}

int			main(int argc, char** argv)
{
	t_struct	s;
	t_app		app;

	if (argc != 2)
		printf("Wrong number of arguments.\n");
	ft_memset(&app, 0, sizeof(app));
	ft_memset(&s, 0, sizeof(s));
	initSDL(&app);
	buildmap(argv[1], &s);
	ft_print2dcarr(s.map);

	app.screenSurface = SDL_GetWindowSurface( app.window );
	SDL_FillRect(app.screenSurface, NULL, SDL_MapRGB( app.screenSurface->format, 0x00, 0xFF, 0xFF ) );
	SDL_UpdateWindowSurface( app.window );
	SDL_Delay(3000);
	SDL_DestroyWindow(app.window);
	cleanup(&app);
	free(s.map);
	printf("444\n");
	return (1);
}
