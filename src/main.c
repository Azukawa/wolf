/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:03:10 by alero             #+#    #+#             */
/*   Updated: 2021/05/27 15:01:26 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int			main(int argc, char** argv)
{
	t_map		*s;
	t_app		*app;
	SDL_Event	e;
	t_player	player;
	
	if (argc != 2)
		ft_printf("Wrong number of arguments.\n");
	ft_memset(&player, 0, sizeof(t_player));
	player.p.x = player.p.y = 100;
	s = ft_memalloc(sizeof(*s));
	app = ft_memalloc(sizeof(*app));
	app->run = 1;
	initSDL(app);
	buildmap(argv[1], s);
	ft_print2dcarr(s->map);
	app->screenSurface = SDL_GetWindowSurface(app->window);
		while(app->run)
		{
			/*
			*	SDL_LockTexture gives us the tex_pitch which is the 'true' size of drawn screen width
			*	(how many pixels are drawn in one level).
			*/
			keyevent(app, &e, &player);
			drawmap(s, app);
			drawplayer(app, &player);

			if(SDL_LockTexture(app->texture, NULL, (void **)&app->tex, &app->tex_pitch) < 0)
				app->run = 0;
			ft_memcpy(app->tex, app->buffer, SCREEN_HEIGHT * app->tex_pitch);
			SDL_UnlockTexture(app->texture);
			if (SDL_RenderCopy(app->renderer, app->texture, NULL, NULL) < 0)
				app->run = 0;
			SDL_RenderPresent(app->renderer);
		}
	
	cleanup(app);

	ft_free_arr(s->map);
	free(s);
	free(app->buffer);
	free(app);

	//SDL_DestroyWindow(app->window);
	ft_printf("Ran untill end\n");
	return (1);
}
