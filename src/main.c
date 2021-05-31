/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:03:10 by alero             #+#    #+#             */
/*   Updated: 2021/05/31 19:01:21 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int			main(int argc, char** argv)
{
	t_map		*s;
	t_app		*app;
	SDL_Event	e;
	t_map_player	player;
	
	if (argc != 2)
		ft_printf("Wrong number of arguments.\n");
	ft_memset(&player, 0, sizeof(t_map_player));
	player.p.x = player.p.y = 100;
	s = ft_memalloc(sizeof(*s));
	app = ft_memalloc(sizeof(*app));
	app->run = 1;
	initSDL(app);

	app->player.pos_x = 3.;
	app->player.pos_y = 3.;
	app->player.angle = 45.;
	
	ft_printf("xxx\n");
	buildmap(argv[1], s);
	ft_print2dcarr(s->map);
	app->screenSurface = SDL_GetWindowSurface(app->window);
		while(app->run)
		{
			keyevent(app, &e, &player, s);

			ft_bzero(app->buffer, SCREEN_HEIGHT * SCREEN_WIDTH); //clear buffer

			raycast(app, s);
			if (app->draw_ui)
				drawmap(s, app);
			/*
			*	SDL_LockTexture gives us the tex_pitch which is the 'true' size of drawn screen width
			*	(how many pixels are drawn in one level).
			*/
			keyevent(app, &e, &player, s);
			//drawplayer(app, &player, s);
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
