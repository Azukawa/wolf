/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:53:10 by eniini            #+#    #+#             */
/*   Updated: 2021/06/18 18:03:36 by alero            ###   ########.fr       */
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
*	TEXTURE STREAMING MAGIC (WIP)
*	rules: texture size is absolute. We need to TRANSLATE relevant pixel data from
*	it to screen.
*	
*/
static void	draw_tex_line(t_app *app, int ray_i, double dist, SDL_Surface *tex)
{
	int			y;
	uint8_t		*pixel;
	uint32_t	argb;
	int			tex_y;
	//int			tex_x;
	//double		offset;
	double		tex_step;

	double		tex_pos;

	tex_step = 1.0 * WALLTEX_H / (app->rc.wall_e - app->rc.wall_s);
	tex_pos = (app->rc.wall_s - HALF_SH + (app->rc.wall_e - app->rc.wall_s) / 2) * tex_step;
	//tex_pos = 0.;
	//offset = tex_step;
	y = app->rc.wall_s;
	//tex_x = ray_i % WALLTEX_W;
	while (y < app->rc.wall_e && y < SCREEN_HEIGHT)
	{
		tex_y = (int)tex_pos % WALLTEX_H;
		tex_pos += tex_step;
		//tex_y = (int)(offset) % WALLTEX_H;
		pixel = (uint8_t *)tex->pixels + tex_y * tex->pitch + app->rc.tex_x * TEX_BPP;
		argb = pixel[0] | pixel[1] << 8 | pixel[2] << 16 | pixel[3] << 24;
		drawpixel(ray_i, y, app->buffer, ft_argb_lerp(argb, SHADE, dist * 0.1));
		//offset += tex_step;
		y++;
	}
}

/*
*	Each vertical slice of the screen is divided into three areas, which
*	are then filled with draw_line() calls. Raycasted walls will have
*	different coloring/texturing depending on their relation to the player.
*/

static void	draw_ray(t_app *app, double dist, int ray_i, t_bool side)
{
	int	wall_s;
	int	wall_e;
	int	offset;

	offset = (int)(HALF_SH / dist);
	app->rc.wall_s = (-offset) + HALF_SH;
	app->rc.wall_e = offset + HALF_SH;
	wall_s = ft_clamp_i(HALF_SH - offset, 1, SCREEN_HEIGHT - 1);
	wall_e = ft_clamp_i(HALF_SH + offset, 1, SCREEN_HEIGHT - 1);
	draw_line(app, (t_point){1, ray_i}, (t_point){wall_s, ray_i}, DEV_CEIL);
	if (!side && (app->rc.ray_d < 270 && app->rc.ray_d > 90))
		draw_line(app, (t_point){wall_s, ray_i}, (t_point){wall_e, ray_i},
			ft_argb_lerp(DEV_WALL_E, SHADE, dist * 0.1));
	else if (!side)
		draw_line(app, (t_point){wall_s, ray_i}, (t_point){wall_e, ray_i},
			ft_argb_lerp(DEV_WALL_W, SHADE, dist * 0.1));
	else if ((app->rc.ray_d > 180 && app->rc.ray_d < 360) || app->rc.ray_d < 0)
		draw_line(app, (t_point){wall_s, ray_i}, (t_point){wall_e, ray_i},
			ft_argb_lerp(DEV_WALL_S, SHADE, dist * 0.1));
	else
		draw_line(app, (t_point){wall_s, ray_i}, (t_point){wall_e, ray_i},
			ft_argb_lerp(DEV_WALL_N, SHADE, dist * 0.1));
	draw_line(app, (t_point){wall_e, ray_i},
		(t_point){SCREEN_HEIGHT, ray_i}, DEV_FLOOR);
}

static void	draw_tex_ray(t_app *app, double dist, int ray_i, t_bool side)
{
	int	wall_s;
	int	wall_e;
	int	offset;

	offset = (int)(HALF_SH / dist);
	app->rc.wall_s = (-offset) + HALF_SH;
	app->rc.wall_e = offset + HALF_SH;
	wall_s = ft_clamp_i(HALF_SH - offset, 1, SCREEN_HEIGHT - 1);
	wall_e = ft_clamp_i(HALF_SH + offset, 1, SCREEN_HEIGHT - 1);
	draw_line(app, (t_point){1, ray_i}, (t_point){wall_s, ray_i}, DEV_CEIL);
	if (!side && (app->rc.ray_d < 270 && app->rc.ray_d > 90))
		draw_tex_line(app, ray_i, dist, app->texlib.walltex_e);
	else if (!side)
		draw_tex_line(app, ray_i, dist, app->texlib.walltex_w);
	else if ((app->rc.ray_d > 180 && app->rc.ray_d < 360) || app->rc.ray_d < 0)
		draw_tex_line(app, ray_i, dist, app->texlib.walltex_s);
	else
		draw_tex_line(app, ray_i, dist, app->texlib.walltex_n);
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
*	Calculates exact x-position of the ray in relation to the texture of
*	the wall being hit.
*/
static void	calc_texpos(t_app *app, t_bool side, double dist, t_fpoint *r)
{
	double	prec_x;

	if (!side && (app->rc.ray_d < 270 && app->rc.ray_d > 90))
		prec_x = -app->player.pos_y + dist * (app->rc.ray_d * RAD_CON);
	else if (!side)
		prec_x = app->player.pos_y + dist * (app->rc.ray_d * RAD_CON); //this is the one that works
	else if ((app->rc.ray_d > 180 && app->rc.ray_d < 360) || app->rc.ray_d < 0)
		prec_x = app->player.pos_x + dist * (app->rc.ray_d * RAD_CON);
	else
		prec_x = app->player.pos_x - dist * (app->rc.ray_d * RAD_CON);
	//if (!side)
	//	prec_x = app->player.pos_y + dist * (app->rc.ray_d * RAD_CON);
	//else
	//	prec_x = app->player.pos_x + dist * (app->rc.ray_d * RAD_CON);
	prec_x -= (floor)(prec_x);
	app->rc.tex_x = (int)(prec_x * (double)WALLTEX_W);
	r->x = r->x; //werror avoidance
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
		calc_texpos(app, side, dist, &ray);
		if (app->draw_tex == TRUE)
			draw_tex_ray(app, dist, ray_i, side);
		else
			draw_ray(app, dist, ray_i, side);
		app->rc.ray_d += app->rc.raycast_unit;
		ray_i++;
	}
}
