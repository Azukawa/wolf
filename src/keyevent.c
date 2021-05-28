/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:53:01 by alero             #+#    #+#             */
/*   Updated: 2021/05/27 17:38:07 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		keyevent(t_app *app, SDL_Event *e, t_map_player *p)
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
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_q) //right rotation
		{
			double old_dir_x = app->player.dir_x;
			app->player.dir_x = app->player.dir_x * cos(-3.) - app->player.dir_y * sin(-3.);
			app->player.dir_y = old_dir_x * sin(-3.) + app->player.dir_y * cos(-3.);
			double old_plane_x = app->player.plane_x;
			app->player.plane_x = app->player.plane_x * cos(-3.) - app->player.plane_y * sin(-3);
			app->player.plane_y = old_plane_x * sin(-3) + app->player.plane_y * cos(-3);
		}
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_e) //left rotation
		{
			double old_dir_x = app->player.dir_x;
			app->player.dir_x = app->player.dir_x * cos(3.) - app->player.dir_y * sin(3.);
			app->player.dir_y = old_dir_x * sin(3.) + app->player.dir_y * cos(3.);
			double old_plane_x = app->player.plane_x;
			app->player.plane_x = app->player.plane_x * cos(3.) - app->player.plane_y * sin(3);
			app->player.plane_y = old_plane_x * sin(3) + app->player.plane_y * cos(3);
		}
	}

}
