/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:53:10 by eniini            #+#    #+#             */
/*   Updated: 2021/06/09 16:12:09 by alero            ###   ########.fr       */
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

static void	draw_tex_line(t_app *app, int wall_s, int wall_e, int ray_i)
{
	int	y;
	int	pixel;

	y = 0;
	while (y < app->rc.walltex->img_h)
	{
		pixel = (ray_i * app->rc.walltex->img_w + y * \
				(app->rc.walltex->bpp / 8));
		drawpixel(ray_i, y, app->buffer, \
				(uint32_t)app->rc.walltex->one_d_addr[pixel]);
		y++;
	}
}

/*
*	NOTE: test what happens if distance > HALF_SH and/or SCREEN_HEIGHT!
*
*	Each vertical slice of the screen is divided into three areas, which
*	are then filled with draw_line() calls. Raycasted walls will have
*	different coloring/texturing depending on their relation to the player.
*/
static void	draw_ray(t_app *app, double dist, int ray_i, t_bool side)
{
	int	wall_s;
	int	wall_e;

	wall_s = ft_clamp_i(HALF_SH - (int)(HALF_SH / dist), 1, SCREEN_HEIGHT);
	wall_e = ft_clamp_i(HALF_SH + (int)(HALF_SH / dist), 1, SCREEN_HEIGHT);
	draw_line(app, (t_point){1, ray_i}, (t_point){wall_s, ray_i}, DEV_CEIL);
	if (!side && (app->rc.ray_d < 270 && app->rc.ray_d > 90))
		draw_line(app, (t_point){wall_s, ray_i}, (t_point){wall_e, ray_i},
			ft_argb_lerp(DEV_WALL_E, DEV_SHADE, dist * 0.1));
	else if (!side)
		draw_line(app, (t_point){wall_s, ray_i}, (t_point){wall_e, ray_i},
			ft_argb_lerp(DEV_WALL_W, DEV_SHADE, dist * 0.1));
	else if ((app->rc.ray_d > 180 && app->rc.ray_d < 360) || app->rc.ray_d < 0)
		draw_line(app, (t_point){wall_s, ray_i}, (t_point){wall_e, ray_i},
			ft_argb_lerp(DEV_WALL_S, DEV_SHADE, dist * 0.1));
	else
		draw_line(app, (t_point){wall_s, ray_i}, (t_point){wall_e, ray_i},
			ft_argb_lerp(DEV_WALL_N, DEV_SHADE, dist * 0.1));
	draw_line(app, (t_point){wall_e, ray_i},
		(t_point){SCREEN_HEIGHT, ray_i}, DEV_FLOOR);
}

/*
*	Following ray's angle one dimension at a time to check if the ray
*	intercepts a wall diagonally or horizontally.
*/
static t_bool	project_ray(t_app *app, t_map *map, t_fpoint *ray)
{
	while (1)
	{
		ray->x += app->rc.ray_cos;
		if (map->map[(int)(ray->y)][(int)(ray->x)] != '0')
			return (FALSE);
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
		draw_ray(app, dist, ray_i, side);
		app->rc.ray_d += app->rc.raycast_unit;
		ray_i++;
	}
}
