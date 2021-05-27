/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:03:10 by alero             #+#    #+#             */
/*   Updated: 2021/05/27 16:33:15 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int			main(int argc, char** argv)
{
	t_map		*s;
	t_app		*app;
	SDL_Event	e;

	if (argc != 2)
		ft_printf("Wrong number of arguments.\n");
	s = ft_memalloc(sizeof(*s));
	app = ft_memalloc(sizeof(*app));
	app->run = 1;
	initSDL(app);

	//app->player.raycast_precision = 64;
	//app->player.raycast_incrementer = //FOV / SCREEN_WIDTH;
	app->player.pos_x = 4.;
	app->player.pos_y = 4.;
	app->player.dir_x = -1;
	app->player.dir_y = 0;
	app->player.plane_x = 0;
	app->player.plane_y = 0.66;

	ft_printf("xxx\n");
	buildmap(argv[1], s);
	ft_printf("yyy\n");
	ft_print2dcarr(s->map);
	ft_printf("zzz\n");
	app->screenSurface = SDL_GetWindowSurface(app->window);
		while(app->run)
		{
			keyevent(app, &e);

			ft_bzero(app->buffer, SCREEN_HEIGHT * SCREEN_WIDTH); //clear buffer

			//drawmap(s, app);
			/*
			t_point p0 = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
			t_point p1 = {SCREEN_WIDTH, SCREEN_HEIGHT};
			t_point p2 = {SCREEN_WIDTH, 0};
			t_point p3 = {0, SCREEN_HEIGHT};
			t_point p4 = {0, 0};
			draw_filled_circle(app, p0, 30, 0xffffff);
			draw_circle(app, p0, 50, 0xffffff);
			draw_line(app, p0, p1, 0xff0000);
			draw_line(app, p0, p2, 0x25ff00);
			draw_line(app, p0, p3, 0x00e3ff);
			draw_line(app, p0, p4, 0xffe000);
			*/
			raycast(app, s);
			/*
			*	SDL_LockTexture gives us the tex_pitch which is the 'true' size of drawn screen width
			*	(how many pixels are drawn in one level).
			*/
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
