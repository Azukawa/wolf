/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:53:10 by eniini            #+#    #+#             */
/*   Updated: 2021/06/09 14:11:06 by alero            ###   ########.fr       */
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

static void	draw_rays(t_app *app, double dist, int ray_i, t_bool side)
{
	int	wall_s;
	int	wall_e;

	wall_s = ft_clamp_i(HALF_SH - floor(HALF_SH / dist), 1, SCREEN_HEIGHT);
	wall_e = ft_clamp_i(HALF_SH + floor(HALF_SH / dist), 1, SCREEN_HEIGHT);
	draw_line(app, (t_point){1, ray_i}, (t_point){wall_s, ray_i}, DEV_CEIL);
	if (!side && (app->rc.ray_d < 270 && app->rc.ray_d > 90))
		draw_line(app, (t_point){wall_s, ray_i}, (t_point){wall_e, ray_i}, \
		ft_argb_lerp(DEV_WALL_E, DEV_SHADE, dist * 0.1));
	else if (!side)
		draw_line(app, (t_point){wall_s, ray_i}, (t_point){wall_e, ray_i}, \
		ft_argb_lerp(DEV_WALL_W, DEV_SHADE, dist * 0.1));
	else if ((app->rc.ray_d > 180 && app->rc.ray_d < 360) || app->rc.ray_d < 0)
		draw_line(app, (t_point){wall_s, ray_i}, (t_point){wall_e, ray_i}, \
		ft_argb_lerp(DEV_WALL_S, DEV_SHADE, dist * 0.1));
	else
		draw_line(app, (t_point){wall_s, ray_i}, (t_point){wall_e, ray_i}, \
		ft_argb_lerp(DEV_WALL_N, DEV_SHADE, dist * 0.1));
	draw_line(app, (t_point){wall_e, ray_i},
		(t_point){SCREEN_HEIGHT, ray_i}, DEV_FLOOR);
}

static void	extwhile(t_fpoint *ray, t_bool *sidehit, t_map *map, t_app *app)
{
	while (1)
	{
		ray->x += app->rc.ray_cos;
		if (map->map[(int)floor(ray->y)][(int)floor(ray->x)] != '0')
		{
			*sidehit = FALSE;
			break ;
		}
		ray->y += app->rc.ray_sin;
		if (map->map[(int)floor(ray->y)][(int)floor(ray->x)] != '0')
		{
			*sidehit = TRUE;
			break ;
		}
	}
}

void	raycast(t_app *app, t_map *map)
{
	t_fpoint	ray;
	double		dist;
	int			ray_i;
	t_bool		sidehit;

	init_raycast_vars(app);
	ray_i = 0;
	while (ray_i < SCREEN_WIDTH)
	{
		ray.x = app->player.pos_x;
		ray.y = app->player.pos_y;
		app->rc.ray_cos = cos(app->rc.ray_d * RAD_CON) / app->rc.precision;
		app->rc.ray_sin = sin(app->rc.ray_d * RAD_CON) / app->rc.precision;
		extwhile(&ray, &sidehit, map, app);
		dist = sqrt((app->player.pos_x - ray.x) * (app->player.pos_x - ray.x) \
			+ (app->player.pos_y - ray.y) * (app->player.pos_y - ray.y));
		dist *= cos((app->rc.ray_d - app->player.angle) * RAD_CON);
		draw_rays(app, dist, ray_i, sidehit);
		app->rc.ray_d += app->rc.raycast_unit;
		ray_i++;
	}
}
