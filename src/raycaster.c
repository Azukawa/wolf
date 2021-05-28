/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:53:10 by eniini            #+#    #+#             */
/*   Updated: 2021/05/28 21:53:32 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	raycast(t_app *app, t_map *map)
{
	//starting raycasting from left side of player direction (halfway of FOV)
	double ray_angle = app->player.angle - FOV_HALF;
	double	increment_value = FOV / SCREEN_WIDTH;
	double	precision = 64.;
	t_fpoint	ray;
	float	ray_cos;
	float	ray_sin;
	float	distance;
	int		wall_height;
	int		ray_count = 0;
	while (ray_count < SCREEN_WIDTH)
	{
		ray.x = app->player.pos_x;
		ray.y = app->player.pos_y;
		ray_cos = cos(ray_angle * RAD_CON) / precision;
		ray_sin = sin(ray_angle * RAD_CON) / precision;
		//ft_printf("raycos:%f|raysin:%f\n", ray_cos, ray_sin);
		while (1)
		{
			ray.x += ray_cos;
			ray.y += ray_sin;
			if (map->map[(int)floor(ray.y)][(int)floor(ray.x)] != '0') //move ray around the int array until we hit on a box that has non-zero value in it.
			{	//we can include more detailed map checking functionality here i.e specific colors I guess
				//ft_printf("hitx:%d|hity:%d\n", (int)floor(ray.y),(int)floor(ray.x));
				break ;
			}
		}
		distance = sqrt((app->player.pos_x - ray.x) * (app->player.pos_x - ray.x) + (app->player.pos_y - ray.y) * (app->player.pos_y - ray.y));
		wall_height = floor(HALF_SH / distance);
		//printf("%d|WH=%d\n", ray_count, wall_height);
		draw_line(app, (t_point){1, ray_count}, (t_point){HALF_SH - wall_height, ray_count}, 0xffa8d7d7); //point with x value of 0 doesn't color anything. bug??
		//ft_printf("ROOF:\t[point0{x:%d|y:%d}\t|\tpoint1{x:%.1f|y:%d}]\n", 0, ray_count, HALF_SH - wall_height, ray_count);
		draw_line(app, (t_point){HALF_SH - wall_height, ray_count}, (t_point){HALF_SH + wall_height, ray_count}, 0xffb65440);
		//ft_printf("WALL:\t[point0{x:%d|y:%d}\t|\tpoint1{x:%d|y:%d}]\n", HALF_SH - wall_height, ray_count, HALF_SH + wall_height, ray_count);
		draw_line(app, (t_point){HALF_SH + wall_height, ray_count}, (t_point){SCREEN_HEIGHT, ray_count}, 0xff22283e);
		//ft_printf("FLOOR:\t[point0{x:%.1f|y:%d}\t|\tpoint1{x:%.1f|y:%d}]\n", HALF_SH + wall_height, ray_count, SCREEN_HEIGHT, ray_count);
		//move the ray angle until whole FOV is drawn
		ray_angle += increment_value;
		ray_count++;
	}
}