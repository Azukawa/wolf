/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initSDL.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:56:35 by eniini            #+#    #+#             */
/*   Updated: 2021/06/10 16:12:04 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	init_SDL(t_app *app)
{
	int		renderFlags;
	int		windowFlags;

	app->run = 1;
	renderFlags = SDL_RENDERER_ACCELERATED;
	windowFlags = 0;
	app->buffer = ft_memalloc(SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(uint32_t));
	ft_bzero(app->buffer, SCREEN_WIDTH * SCREEN_HEIGHT);
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		exit(ft_printf("couldn't initialize SDL: %s\n", SDL_GetError()));
	app->window = SDL_CreateWindow(WOLF_HEADER, SDL_WINDOWPOS_UNDEFINED, \
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);
	if (!app->window)
		exit(ft_printf("failed to open %d x %d window %s\n", SCREEN_WIDTH, \
	SCREEN_HEIGHT, SDL_GetError()));
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	app->renderer = SDL_CreateRenderer(app->window, -1, renderFlags);
	if (!app->renderer)
		exit(ft_printf("Failed to create renderer: %s\n", SDL_GetError()));
	app->texture = SDL_CreateTexture(app->renderer, SDL_PIXELFORMAT_ARGB8888, \
			SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!app->texture)
		exit(ft_printf("Failed to create texture: %s\n", SDL_GetError()));
	if ((SDL_SetTextureBlendMode(app->texture, SDL_BLENDMODE_BLEND)))
		ft_getout("[SDL2]failed to set texture blending mode");
}

void	init_player_vars(t_app *app)
{
	app->player.pos_x = 3.;
	app->player.pos_y = 3.;
	app->player.angle = 45.;
	app->player.fov = 60;
	app->player.move_u = 0.5;
	app->player.rotation_u = 5.0;
}
