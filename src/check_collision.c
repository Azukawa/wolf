/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:11:41 by alero             #+#    #+#             */
/*   Updated: 2021/06/07 16:58:40 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

/*
 *			Check collision checks if the player position is inside a wall,
 *			if so, function returns player position to last known position.
 *			Also pultiple different checks to make sure that that
 *			player position is legal.
 */

static void	var_checks(t_app *app, t_map *map)
{
	if (app->player.angle > 360)
		app->player.angle = app->player.angle - 360;
	if (app->player.angle < 0)
		app->player.angle = app->player.angle + 360;
	if (app->player.pos_y > map->h)
		app->player.pos_y = (double)map->h;
	if (app->player.pos_x > map->w)
		app->player.pos_x = (double)map->w;
	if (app->player.pos_x < 0)
		app->player.pos_x = 0.;
	if (app->player.pos_y < 0)
		app->player.pos_y = 0.;
}

void	check_collision(t_app *app, t_map *map)
{
	static double	old_pos_x;
	static double	old_pos_y;

	var_checks(app, map);
	if (map->map[(int)floor(app->player.pos_y)] \
	[(int)floor(app->player.pos_x)] == '0')
	{
		old_pos_x = app->player.pos_x;
		old_pos_y = app->player.pos_y;
	}
	else
	{	
		ft_printf("BLOCKED!\n");
		app->player.pos_x = old_pos_x;
		app->player.pos_y = old_pos_y;
	}
}
