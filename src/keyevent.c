/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:53:01 by alero             #+#    #+#             */
/*   Updated: 2021/05/27 14:49:23 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		keyevent(t_app *app, SDL_Event *e, t_player *p)
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
	}

}
