/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:03:10 by alero             #+#    #+#             */
/*   Updated: 2021/04/20 13:07:15 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

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
