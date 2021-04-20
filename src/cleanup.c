/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:58:18 by eniini            #+#    #+#             */
/*   Updated: 2021/04/20 13:09:28 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	cleanup(t_app *app)
{
	SDL_DestroyRenderer(app->renderer);
	SDL_DestroyWindow(app->window);
}
