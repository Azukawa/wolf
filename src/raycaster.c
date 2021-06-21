/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:53:10 by eniini            #+#    #+#             */
/*   Updated: 2021/06/21 18:16:43 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
*	Raycaster increments from one edge of the player FOV to the another.
*	ray_d is the starting position
*	ray_unit is the degree unit by which ray_d is incremented by
*	precision is the arbitary-sized hypotenuse for raycasting calculations.
*/
static void	init_raycast_vars(t_app *app)
{
	app->rc.ray_d = app->player.angle - app->player.fov / 2.;
	app->rc.raycast_unit = (double)app->player.fov / (double)SCREEN_WIDTH;
	app->rc.precision = 64;
}

/*
*	Following ray's angle one dimension at a time to check if the ray
*	intercepts a wall diagonally or horizontally.
*/
static t_bool	project_ray(t_app *app, t_map *map, t_fpoint *ray)
{
	while (1)
	{
		if (ray->x + app->rc.ray_cos <= 0 || ray->x + app->rc.ray_cos >= map->w)
			return (FALSE);
		ray->x += app->rc.ray_cos;
		if (map->map[(int)(ray->y)][(int)(ray->x)] != '0')
			return (FALSE);
		if (ray->y + app->rc.ray_sin <= 0 || ray->y + app->rc.ray_sin >= map->h)
			return (TRUE);
		ray->y += app->rc.ray_sin;
		if (map->map[(int)(ray->y)][(int)(ray->x)] != '0')
			return (TRUE);
	}
}

/*
*	Projects rays for the length of the player's FOV using trigonometry
*	and calculates the distance between ray's origin and the wall it hits.
*/

void	raycast(t_app *app, t_map *map)
{
	t_fpoint	ray;
	double		dist;
	int			ray_i;
	t_bool		side;

	init_raycast_vars(app);
	ray_i = 0;
	while (ray_i < SCREEN_WIDTH)
	{
		ray.x = app->player.pos_x;
		ray.y = app->player.pos_y;
		app->rc.ray_cos = cos(app->rc.ray_d * RAD_CON) / app->rc.precision;
		app->rc.ray_sin = sin(app->rc.ray_d * RAD_CON) / app->rc.precision;
		side = project_ray(app, map, &ray);
		dist = sqrt((app->player.pos_x - ray.x) * (app->player.pos_x - ray.x)
				+ (app->player.pos_y - ray.y) * (app->player.pos_y - ray.y));
		dist *= cos((app->rc.ray_d - app->player.angle) * RAD_CON);
		if (app->draw_tex == TRUE)
			draw_tex_ray(app, dist, ray_i, side);
		else
			draw_flat_ray(app, dist, ray_i, side);
		app->rc.ray_d += app->rc.raycast_unit;
		ray_i++;
	}
}
