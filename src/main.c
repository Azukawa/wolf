/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:03:10 by alero             #+#    #+#             */
/*   Updated: 2021/06/02 23:15:21 by eniini           ###   ########.fr       */
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
	init_SDL(app);
	init_player_vars(app);
	ft_printf("xxx\n");
	buildmap(argv[1], s);
	//ft_print2dcarr(s->map);
	app->screenSurface = SDL_GetWindowSurface(app->window);

	t_gfxinfo *bmp = ft_load_bmp("resources/testpattern.bmp");
	if (!bmp)
		ft_printf("failed to load bmp file");
	ft_create_bmp("output.bmp", bmp);
	/*
	uint32_t amask = 0;
	uint32_t rmask = 0xff0000;
	uint32_t gmask = 0x00ff00;
	uint32_t bmask = 0x0000ff;
	SDL_Surface *bmpsurf = SDL_CreateRGBSurfaceFrom(bmp->one_d_addr, bmp->img_width, bmp->img_height, sizeof(unsigned char), 3 * bmp->img_width, rmask, gmask, bmask, amask);
	if (!bmpsurf)
		ft_getout(SDL_GetError());
	SDL_Texture *bmptex = SDL_CreateTextureFromSurface(app->renderer, bmpsurf);
	if (!bmptex)
		ft_getout(SDL_GetError());
	SDL_Rect	bmprct;
	bmprct.h = bmp->img_height;
	bmprct.w = bmp->img_width;
	bmprct.x = 0;
	bmprct.y = 0;
	*/
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
				ft_getout(SDL_GetError());
		ft_memcpy(app->tex, app->buffer, SCREEN_HEIGHT * app->tex_pitch);
		SDL_UnlockTexture(app->texture);
		if (SDL_RenderCopy(app->renderer, app->texture, NULL, NULL) < 0)
			ft_getout(SDL_GetError());
		//if (SDL_RenderCopy(app->renderer, bmptex, NULL, &bmprct) < 0)
		//	ft_getout(SDL_GetError());
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
