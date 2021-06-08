/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:53:10 by eniini            #+#    #+#             */
/*   Updated: 2021/06/08 20:03:42 by eniini           ###   ########.fr       */
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
/*
static void	draw_tex_line(t_app *app, int wall_start, int wall_end, int ray_count)
{
	double wall_x; // where wall is hit

	while (x < app->rc.walltex->img_h)
	{
		pixel = (ray_count * app->rc.walltex->img_w + x * (app->rc.walltex->bpp / 8));
		drawpixel(texture_x, ray_count, app->buffer, (uint32_t)app->rc.walltex->one_d_addr[pixel]);
		x++;
	}
}*/


void	raycast(t_app *app, t_map *map)
{
	t_fpoint	ray;
	double		distance;
	int			ray_count;
	int			wall_start;
	int			wall_end;
	t_bool		sidehit;

	init_raycast_vars(app);
	ray_count = 0;
	sidehit = FALSE;
	while (ray_count < SCREEN_WIDTH)
	{
		ray.x = app->player.pos_x;
		ray.y = app->player.pos_y;
		app->rc.ray_cos = cos(app->rc.ray_angle * RAD_CON) / app->rc.precision;
		app->rc.ray_sin = sin(app->rc.ray_angle * RAD_CON) / app->rc.precision;
		while (1)
		{
			ray.x += app->rc.ray_cos;
			if (map->map[(int)floor(ray.y)][(int)floor(ray.x)] != '0') //move ray around the int array until we hit on a box that has non-zero value in it.
			{
				sidehit = FALSE;
				break; //we can include more detailed map checking functionality here i.e specific colors I guess
			}
			ray.y += app->rc.ray_sin;
			if (map->map[(int)floor(ray.y)][(int)floor(ray.x)] != '0') //move ray around the int array until we hit on a box that has non-zero value in it.
			{
				sidehit = TRUE;
				break; //we can include more detailed map checking functionality here i.e specific colors I guess
			}
		}
		distance = sqrt((app->player.pos_x - ray.x) * (app->player.pos_x - ray.x) + (app->player.pos_y - ray.y) * (app->player.pos_y - ray.y));
		distance *= cos(RAD_CON * (app->rc.ray_angle - app->player.angle)); //fisheye fix
		wall_start = ft_clamp_i(HALF_SH - floor(HALF_SH / distance), 1, SCREEN_HEIGHT);
		wall_end = ft_clamp_i(HALF_SH + floor(HALF_SH / distance), 1, SCREEN_HEIGHT);

		draw_line(app, (t_point){1, ray_count}, (t_point){wall_start, ray_count}, DEV_CEILCOL); //point with x value of 0 doesn't color anything. bug??
		/*
		int	texturepositionx = (int)floor(fmod((app->rc.walltex->img_w * (ray.x + ray.y)), (double)app->rc.walltex->img_w));
		double	y_incrementer = (SCREEN_WIDTH * 2) / app->rc.walltex->img_h;
		double	y = wall_start;
		double	x = ray_count;

		for (int i = 0; i < app->rc.walltex->img_h; i++)
		{
			unsigned char	*r = app->rc.walltex->one_d_addr[i * app->rc.walltex->img_w + texturepositionx * (app->rc.walltex->bpp / 8)];
			unsigned char	*g = app->rc.walltex->one_d_addr[i * app->rc.walltex->img_w + texturepositionx * (app->rc.walltex->bpp / 8) + 1];
			unsigned char	*b = app->rc.walltex->one_d_addr[i * app->rc.walltex->img_w + texturepositionx * (app->rc.walltex->bpp / 8) + 2];
			uint32_t		color = 0xff | (*r << 8) | (*g << 16) | (*b << 24);
			ft_printf("%u\n", color);
			draw_line(app, (t_point){x, y}, (t_point){x, y + y_incrementer}, color);
			y += y_incrementer;
		}*/
		if (!sidehit && (app->rc.ray_angle < 270 && app->rc.ray_angle > 90))
			draw_line(app, (t_point){wall_start, ray_count}, (t_point){wall_end, ray_count}, ft_argb_lerp(DEV_WALLCOL_E, DEV_SHADECOL, distance / 10));
		else if (!sidehit)
			draw_line(app, (t_point){wall_start, ray_count}, (t_point){wall_end, ray_count}, ft_argb_lerp(DEV_WALLCOL_W, DEV_SHADECOL, distance / 10));
		else if (app->rc.ray_angle > 180 && app->rc.ray_angle < 360)
			draw_line(app, (t_point){wall_start, ray_count}, (t_point){wall_end, ray_count}, ft_argb_lerp(DEV_WALLCOL_S, DEV_SHADECOL, distance / 10));
		else
			draw_line(app, (t_point){wall_start, ray_count}, (t_point){wall_end, ray_count}, ft_argb_lerp(DEV_WALLCOL_N, DEV_SHADECOL, distance / 10));
		draw_line(app, (t_point){wall_end, ray_count}, (t_point){SCREEN_HEIGHT, ray_count}, DEV_FLOORCOL);
		app->rc.ray_angle += app->rc.raycast_unit;
		ray_count++;  //move the ray angle until whole FOV is drawn

		//testing new enviroment !
	}
}
