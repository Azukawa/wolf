/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:03:10 by alero             #+#    #+#             */
/*   Updated: 2021/06/21 18:59:22 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	mainloop(t_map *s, t_app *app, SDL_Event *e)
{
	while (app->run)
	{
		keyevent(app, e);
		ft_bzero(app->buffer, SCREEN_HEIGHT * SCREEN_WIDTH);
		check_collision(app, s);
		raycast(app, s);
		if (app->draw_ui)
			drawmap(s, app);
		if (SDL_LockTexture(app->texture, NULL, (void **)&app->tex, \
					&app->tex_pitch) < 0)
			ft_getout(SDL_GetError());
		ft_memcpy(app->tex, app->buffer, SCREEN_HEIGHT * app->tex_pitch);
		SDL_UnlockTexture(app->texture);
		if (SDL_RenderCopy(app->renderer, app->texture, NULL, NULL) < 0)
			ft_getout(SDL_GetError());
		fps_counter(app);
		SDL_RenderPresent(app->renderer);
	}
}

static int	define_player_pos(t_map *map, t_app *app)
{
	int	x;
	int	y;
	int	boool;

	x = -1;
	y = -1;
	boool = 0;
	while (++y < map->h)
	{
		while (++x < map->w)
		{
			if (map->map[y][x] == '$')
			{
				if (boool == 0)
				{
					app->player.pos_x = x + 0.5;
					app->player.pos_y = y + 0.5;
					boool = 1;
				}
				map->map[y][x] = '0';
			}
		}
		x = -1;
	}
	return ((boool == 0) * -1);
}

/*
*	Loads given image file into texture data pointer [tex] in given format.
*/
static SDL_Surface	*bitmap_load(SDL_PixelFormat *format, char *file)
{
	SDL_Surface		*raw_bmp;
	SDL_Surface		*result;

	raw_bmp = SDL_LoadBMP(file);
	if (!raw_bmp)
		ft_getout(SDL_GetError());
	result = SDL_ConvertSurface(raw_bmp, format, 0);
	if (!result)
		ft_getout(SDL_GetError());
	SDL_FreeSurface(raw_bmp);
	ft_printf("%d\n", result->pitch);
	return (result);
}

static void	load_textures(t_app *app)
{
	SDL_PixelFormat	*format;

	format = SDL_AllocFormat(SDL_PIXELFORMAT_ARGB8888);
	if (!format)
		ft_getout(SDL_GetError());
	app->texlib.walltex_e = bitmap_load(format, WALL_E);
	app->texlib.walltex_s = bitmap_load(format, WALL_S);
	app->texlib.walltex_n = bitmap_load(format, WALL_N);
	app->texlib.walltex_w = bitmap_load(format, WALL_W);
}

int	main(int	argc, char	**argv)
{
	t_map			s;
	t_app			app;
	SDL_Event		e;
	int				x;

	ft_bzero(&s, sizeof(t_map));
	ft_bzero(&app, sizeof(t_app));
	if (argc != 2)
		ft_getout("Wrong number of arguments.");
	init_SDL(&app);
	init_player_vars(&app);
	x = buildmap(argv[1], &s);
	x = define_player_pos(&s, &app);
	if (x == -1 || s.w < 3 || s.h < 3)
		ft_getout("File does not exist or is of incorrect type.");
	load_textures(&app);
	mainloop(&s, &app, &e);
	cleanup(&app);
	ft_free_arr(s.map);
	free(app.buffer);
	return (1);
}
