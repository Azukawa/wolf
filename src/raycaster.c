/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:53:10 by eniini            #+#    #+#             */
/*   Updated: 2021/05/31 17:24:29 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	raycast(t_app *app, t_map *map)
{
	double ray_angle = app->player.angle - FOV_HALF; //starting raycasting from left side of player direction (halfway of FOV)
	double	increment_value = FOV / SCREEN_WIDTH;
	double	precision = 64.;
	t_fpoint	ray;
	float	ray_cos;
	float	ray_sin;
	float	distance;
	int		wall_height;
	int		ray_count = 0;
	int wallstart, wallend;
	while (ray_count < SCREEN_WIDTH)
	{
		ray.x = app->player.pos_x;
		ray.y = app->player.pos_y;
		ray_cos = cos(ray_angle * RAD_CON) / precision;
		ray_sin = sin(ray_angle * RAD_CON) / precision;
		while (1)
		{
			ray.x += ray_cos;
			ray.y += ray_sin;
			if (map->map[(int)floor(ray.y)][(int)floor(ray.x)] != '0') //move ray around the int array until we hit on a box that has non-zero value in it.
			{	//we can include more detailed map checking functionality here i.e specific colors I guess
				break ;
			}
		}
		distance = sqrt((app->player.pos_x - ray.x) * (app->player.pos_x - ray.x) + (app->player.pos_y - ray.y) * (app->player.pos_y - ray.y));
		distance *= cos(RAD_CON * (ray_angle - app->player.angle)); //fisheye fix
		wall_height = floor(HALF_SH / distance);
		wallstart = ft_clamp_i(HALF_SH - wall_height, 1, SCREEN_HEIGHT); //we can maybe use these for drawing textures
		wallend = ft_clamp_i(HALF_SH + wall_height, 1, SCREEN_HEIGHT); //^
		draw_line(app, (t_point){1, ray_count}, (t_point){wallstart, ray_count}, 0xffa8d7d7); //point with x value of 0 doesn't color anything. bug??
		draw_line(app, (t_point){wallstart, ray_count}, (t_point){wallend, ray_count}, ft_argb_lerp(0xffb65440, 0xff211b4c, distance / 10));
		draw_line(app, (t_point){wallend, ray_count}, (t_point){SCREEN_HEIGHT, ray_count}, 0xff22283e);
		ray_angle += increment_value;
		ray_count++;  //move the ray angle until whole FOV is drawn
	}
}