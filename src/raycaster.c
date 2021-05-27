/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:53:10 by eniini            #+#    #+#             */
/*   Updated: 2021/05/27 17:06:18 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	raycast(t_app *app, t_map *map)
{
	//t_floatpoint	ray;
	//starting raycasting from left side of player direction (halfway of FOV)
	//float	ray_cos;
	//float	ray_sin;
	//float	distance;
	//int		wall_height;
	//int		ray_count = 0;
	
	int x = 0;
	while (x < SCREEN_WIDTH)
	{
		double	camera_x = 2 * x / (float)SCREEN_WIDTH - 1; //x-coordinate in camera space
		double	raydir_x = app->player.dir_x + app->player.plane_x * camera_x;
		double	raydir_y = app->player.dir_y + app->player.plane_y * camera_x;
		//current map box
		int map_x = (int)app->player.pos_x;
		int map_y = (int)app->player.pos_y;
		//length of the ray from current posititon to the next x/y side
		double	side_dist_x;
		double	side_dist_y;
		//length of the ray from one x/y side to the next x/y side
		double delta_dist_x;
		if (raydir_x == 0)
			delta_dist_x = 0;
		else
			delta_dist_x = fabs(1 / raydir_x);
		double delta_dist_y;
		if (raydir_y == 0)
			delta_dist_y = 0;
		else
			delta_dist_y = fabs(1 / raydir_y);
		double perp_wall_dist;
		//what direction to step in x/y (+1 or -1)
		int	step_x;
		int	step_y;
		int hit = 0; //was wall hit?
		int side; //which side it was hit from
		//calculate step and initial side_dist
		if (raydir_x < 0)
		{
			step_x = -1;
			side_dist_x = (app->player.pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - app->player.pos_x) * delta_dist_x;
		}
		if (raydir_y < 0)
		{
			step_y = -1;
			side_dist_y = (app->player.pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - app->player.pos_y) * delta_dist_y;
		}
		//DDA algorithm
		while (hit == 0)
		{
			//jump to the next square, or in x or in y direction
			if (side_dist_x < side_dist_x)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (map->map[map_y][map_x] != '0')
				hit = 1;
		}
		//calculate distance projected on camera direction
		if (side == 0)
			perp_wall_dist = (map_x - app->player.pos_x + (1 - step_x) / 2) / raydir_x;
		else
			perp_wall_dist = (map_y - app->player.pos_y + (1 - step_y) / 2) / raydir_y;
		//calculate height of line to drawn on screen
		int line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
		//calculate lowest hand highest pixel for drawline
		int drawstart = -line_height / 2 + SCREEN_HEIGHT / 2;
		if (drawstart < 0)
			drawstart = 0;
		int drawend = line_height / 2 + SCREEN_HEIGHT / 2;
		if (drawend > SCREEN_HEIGHT)
			drawend = SCREEN_HEIGHT;
		draw_line(app, (t_point){x, drawstart}, (t_point){x, drawend}, 0xff3200);
		x++;
	}
	/*while (ray_count < SCREEN_WIDTH)
	{
		ray_cos = cos((RAD_CON * ray_angle) / app->player.raycast_precision);
		ray_sin = sin((RAD_CON * ray_angle) / app->player.raycast_precision);
		ray = (t_floatpoint){app->player.xpos, app->player.ypos}; //init ray position
		while (1)
		{
			ray.x += ray_cos;
			ray.y += ray_sin;
			if (map->map[(int)floor(ray.y)][(int)floor(ray.x)] != '0') //move ray around the int array until we hit on a box that has non-zero value in it.
				break ;
		}
		distance = sqrt(pow(app->player.xpos - ray.x, 2) + pow(app->player.ypos - ray.y, 2));
		wall_height = floor(HALF_SH / distance);
		ft_printf("%d\n", wall_height);
		//draw_line(app, (t_point){app->player.xpos * SCREEN_WIDTH / map->w, app->player.ypos * SCREEN_HEIGHT / map->h},
		//(t_point){ray.x * SCREEN_WIDTH / map->w, ray.y * SCREEN_HEIGHT / map->h}, 0xff0000);
		draw_line(app, (t_point){ray_count, 0}, (t_point){ray_count, HALF_SH - wall_height}, 0x23ff00);
		draw_line(app, (t_point){ray_count, HALF_SH - wall_height}, (t_point){ray_count, HALF_SH + wall_height}, 0x528aab);
		draw_line(app, (t_point){ray_count, HALF_SH + wall_height}, (t_point){ray_count, SCREEN_HEIGHT}, 0xff2200);
		
		ray_angle += app->player.raycast_incrementer;
		ray_count++;
	}*/
}