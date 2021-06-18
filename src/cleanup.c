/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:58:18 by eniini            #+#    #+#             */
/*   Updated: 2021/06/18 17:04:02 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	cleanup(t_app *app)
{
	SDL_FreeSurface(app->texlib.walltex_n);
	SDL_FreeSurface(app->texlib.walltex_e);
	SDL_FreeSurface(app->texlib.walltex_s);
	SDL_FreeSurface(app->texlib.walltex_w);
	SDL_DestroyTexture(app->texture);
	SDL_DestroyRenderer(app->renderer);
	SDL_DestroyWindow(app->window);
	SDL_Quit();
}
