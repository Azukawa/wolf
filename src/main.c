/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:03:10 by alero             #+#    #+#             */
/*   Updated: 2021/06/09 14:52:01 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"
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

int	main(int	argc, char	**argv)
{
	t_map			*s;
	t_app			*app;
	SDL_Event		e;
	t_gfxinfo		*bmp;

	if (argc != 2)
		ft_printf("Wrong number of arguments.\n");
	s = ft_memalloc(sizeof(*s));
	app = ft_memalloc(sizeof(*app));
	app->run = 1;
	init_SDL(app);
	init_player_vars(app);
	buildmap(argv[1], s);
	app->screenSurface = SDL_GetWindowSurface(app->window);
	bmp = ft_load_bmp("resources/testpattern.bmp");
	app->rc.walltex = bmp;
	mainloop(s, app, &e);
	cleanup(app);
	ft_free_arr(s->map);
	free(s);
	free(app->buffer);
	free(app);
	ft_printf("Ran untill end\n");
	return (1);
}
