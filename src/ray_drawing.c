/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:13:54 by eniini            #+#    #+#             */
/*   Updated: 2021/06/18 18:17:18 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Each vertical slice of the screen is divided into three areas, which
**	are then filled with draw_line() calls. Raycasted walls will have
**	different coloring/texturing depending on their relation to the player.
*/

#include "wolf.h"

/*
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
	tex_pos = (app->rc.wall_s - HALF_SH + (app->rc.wall_e - app->rc.wall_s) / 2)
		* tex_step;
	//tex_pos = 0.;
	//offset = tex_step;
	y = app->rc.wall_s;
	//tex_x = ray_i % WALLTEX_W;
	while (y < app->rc.wall_e && y < SCREEN_HEIGHT)
	{
		tex_y = (int)tex_pos % WALLTEX_H;
		tex_pos += tex_step;
		//tex_y = (int)(offset) % WALLTEX_H;
		pixel = (uint8_t *)tex->pixels + tex_y * tex->pitch + app->rc.tex_x
		* TEX_BPP;
		argb = pixel[0] | pixel[1] << 8 | pixel[2] << 16 | pixel[3] << 24;
		drawpixel(ray_i, y, app->buffer, ft_argb_lerp(argb, SHADE, dist * 0.1));
		//offset += tex_step;
		y++;
	}
}

/*
*
*/
void	draw_flat_ray(t_app *app, double dist, int ray_i, t_bool side)
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

/*
*
*/
void	draw_tex_ray(t_app *app, double dist, int ray_i, t_bool side)
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