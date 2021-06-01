/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:53:10 by eniini            #+#    #+#             */
/*   Updated: 2021/06/01 10:08:51 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
*	Raycaster increments from one edge of the player FOV to the another.
*	ray_angle is the starting position
*	ray_unit is the degree unit by which ray_angle is incremented by
*	precision is the arbitary-sized hypotenuse for raycasting calculations.
*/
static void	init_raycast_vars(t_app *app)
{
	app->rc.ray_angle = app->player.angle - app->player.fov / 2.;
	app->rc.raycast_unit = (double)app->player.fov / (double)SCREEN_WIDTH;
	app->rc.precision = 64; //in case we want to change this somewhere
}

void	raycast(t_app *app, t_map *map)
{
	t_fpoint	ray;
	double		distance;
	int			ray_count;
	int			wallstart;
	int			wallend;

	init_raycast_vars(app);
	ray_count = 0;
	while (ray_count < SCREEN_WIDTH)
	{
		ray.x = app->player.pos_x;
		ray.y = app->player.pos_y;
		app->rc.ray_cos = cos(app->rc.ray_angle * RAD_CON) / app->rc.precision;
		app->rc.ray_sin = sin(app->rc.ray_angle * RAD_CON) / app->rc.precision;
		while (1)
		{
			ray.x += app->rc.ray_cos;
			ray.y += app->rc.ray_sin;
			if (map->map[(int)floor(ray.y)][(int)floor(ray.x)] != '0') //move ray around the int array until we hit on a box that has non-zero value in it.
				break; //we can include more detailed map checking functionality here i.e specific colors I guess
		}
		distance = sqrt((app->player.pos_x - ray.x) * (app->player.pos_x - ray.x) + (app->player.pos_y - ray.y) * (app->player.pos_y - ray.y));
		distance *= cos(RAD_CON * (app->rc.ray_angle - app->player.angle)); //fisheye fix
		wallstart = ft_clamp_i(HALF_SH - floor(HALF_SH / distance), 1, SCREEN_HEIGHT); //we can maybe use these for drawing textures
		wallend = ft_clamp_i(HALF_SH + floor(HALF_SH / distance), 1, SCREEN_HEIGHT); //^
		draw_line(app, (t_point){1, ray_count}, (t_point){wallstart, ray_count}, 0xffa8d7d7); //point with x value of 0 doesn't color anything. bug??
		draw_line(app, (t_point){wallstart, ray_count}, (t_point){wallend, ray_count}, ft_argb_lerp(0xffb65440, 0xff211b4c, distance / 10));
		draw_line(app, (t_point){wallend, ray_count}, (t_point){SCREEN_HEIGHT, ray_count}, 0xff22283e);
		app->rc.ray_angle += app->rc.raycast_unit;
		ray_count++;  //move the ray angle until whole FOV is drawn
	}
}
