/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:53:10 by eniini            #+#    #+#             */
/*   Updated: 2021/06/09 11:15:53 by eniini           ###   ########.fr       */
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
static void	draw_tex_line(t_app *app, int wall_s, int wall_e, int ray_i)
{
	double wall_x; // where wall is hit

	while (x < app->rc.walltex->img_h)
	{
		pixel = (ray_i * app->rc.walltex->img_w + x * (app->rc.walltex->bpp / 8));
		drawpixel(texture_x, ray_i, app->buffer, (uint32_t)app->rc.walltex->one_d_addr[pixel]);
		x++;
	}
}*/
/*
int	texturepositionx = (int)floor(fmod((app->rc.walltex->img_w * (ray.x + ray.y)), (double)app->rc.walltex->img_w));
double	y_incrementer = (SCREEN_WIDTH * 2) / app->rc.walltex->img_h;
double	y = wall_s;
double	x = ray_i;
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

static void	draw_rays(t_app *app, double dist, int ray_i, t_bool side)
{
	int	wall_s;
	int	wall_e;

	wall_s = ft_clamp_i(HALF_SH - floor(HALF_SH / dist), 1, SCREEN_HEIGHT);
	wall_e = ft_clamp_i(HALF_SH + floor(HALF_SH / dist), 1, SCREEN_HEIGHT);
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
		while (1)
		{
			ray.x += app->rc.ray_cos;
			if (map->map[(int)floor(ray.y)][(int)floor(ray.x)] != '0')
			{
				sidehit = FALSE;
				break;
			}
			ray.y += app->rc.ray_sin;
			if (map->map[(int)floor(ray.y)][(int)floor(ray.x)] != '0')
			{
				sidehit = TRUE;
				break;
			}
		}
		dist = sqrt((app->player.pos_x - ray.x) * (app->player.pos_x - ray.x)
			+ (app->player.pos_y - ray.y) * (app->player.pos_y - ray.y));
		dist *= cos((app->rc.ray_d - app->player.angle) * RAD_CON);
		draw_rays(app, dist, ray_i, sidehit);
		app->rc.ray_d += app->rc.raycast_unit;
		ray_i++;
	}
}
