/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:53:01 by alero             #+#    #+#             */
/*   Updated: 2021/06/01 10:05:49 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		keyevent(t_app *app, SDL_Event *e, t_map_player *p, t_map *map)
{
	while (SDL_PollEvent(e))
	{
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE)
			app->run = 0;
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_LEFT)
			p->p.x = p->p.x - 1;
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_RIGHT)
			p->p.x = p->p.x + 1;
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_UP)
			p->p.y = p->p.y - 1;
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_DOWN)
			p->p.y = p->p.y + 1;
	//MOVEMENT AND COLLISION CHECKS
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_w)
		{
			double new_pos_x = app->player.pos_x + cos(app->player.angle * RAD_CON) * app->player.move_u;
			double new_pos_y = app->player.pos_y + sin(app->player.angle * RAD_CON) * app->player.move_u;
			if (map->map[(int)floor(new_pos_y)][(int)floor(new_pos_x)] == '0')
			{
				app->player.pos_x = new_pos_x;
				app->player.pos_y = new_pos_y;
			}
		}
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_s)
		{
			double new_pos_x = app->player.pos_x - cos(app->player.angle * RAD_CON) * app->player.move_u;
			double new_pos_y = app->player.pos_y - sin(app->player.angle * RAD_CON) * app->player.move_u;
			if (map->map[(int)floor(new_pos_y)][(int)floor(new_pos_x)] == '0')
			{
				app->player.pos_x = new_pos_x;
				app->player.pos_y = new_pos_y;
			}
		}
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_a)
			app->player.angle -= app->player.rotation_u;
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_d)
			app->player.angle += app->player.rotation_u;
	// DRAW UI OR NOT
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_i)
		{
			if (app->draw_ui)
				app->draw_ui = FALSE;
			else
				app->draw_ui = TRUE;
		}
	}

}
