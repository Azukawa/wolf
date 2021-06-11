/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:53:01 by alero             #+#    #+#             */
/*   Updated: 2021/06/11 16:51:51 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"
static void	key_forward(double *new_pos_x, double *new_pos_y, t_app *app)
{
	*new_pos_x = app->player.pos_x + cos(app->player.angle * \
			RAD_CON) * app->player.move_u;
	*new_pos_y = app->player.pos_y + sin(app->player.angle * \
			RAD_CON) * app->player.move_u;
	app->player.pos_x = *new_pos_x;
	app->player.pos_y = *new_pos_y;
}

static void	key_backward(double *new_pos_x, double *new_pos_y, t_app *app)
{
	*new_pos_x = app->player.pos_x - cos(app->player.angle * \
		RAD_CON) * app->player.move_u;
	*new_pos_y = app->player.pos_y - sin(app->player.angle * \
		RAD_CON) * app->player.move_u;
	app->player.pos_x = *new_pos_x;
	app->player.pos_y = *new_pos_y;
}

static void	key_ui(t_app *app)
{
	if (app->draw_ui)
		app->draw_ui = FALSE;
	else
		app->draw_ui = TRUE;
}

void	keyevent(t_app *app, SDL_Event *e)
{
	double	new_pos_x;
	double	new_pos_y;

	while (SDL_PollEvent(e))
	{
		if (e->type == SDL_KEYDOWN && (e->key.keysym.sym == SDLK_x \
					|| e->key.keysym.sym == SDLK_ESCAPE))
			app->run = 0;
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_w)
			key_forward(&new_pos_x, &new_pos_y, app);
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_s)
			key_backward(&new_pos_x, &new_pos_y, app);
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_a)
			app->player.angle -= app->player.rotation_u;
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_d)
			app->player.angle += app->player.rotation_u;
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_i)
			key_ui(app);
		if (e->type == SDL_WINDOWEVENT && e->window.event == \
				SDL_WINDOWEVENT_CLOSE)
			app->run = 0;
	}
}
