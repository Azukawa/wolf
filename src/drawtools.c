/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawtools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:12:29 by eniini            #+#    #+#             */
/*   Updated: 2021/05/26 15:06:09 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

/*
*	Line drawing algorithm between two point coordinates.
*	Initial checks make sure that drawing works for all angles into
*	every direction. After that, drawline() plots
*	a line of pixels from [point0] to [point1].
*/
void		draw_line(t_app *wolf, t_point p0, t_point p1, int color)
{
	int		derror;
	int		error;
	int		x;
	int		y;
	t_bool	flip;

	flip = FALSE;
	if (abs(p0.x - p1.x) < abs(p0.y - p1.y))
	{
		ft_swap(&p0.x, &p0.y, sizeof(int));
		ft_swap(&p1.x, &p1.y, sizeof(int));
		flip = TRUE;
	}
	if (p0.x > p1.x)
	{
		ft_swap(&p0.x, &p1.x, sizeof(int));
		ft_swap(&p0.y, &p1.y, sizeof(int));
	}
	//printf("p0[x=%d|y=%d]  p1[x=%d|y=%d]\n", p0.x, p0.y, p1.x, p1.y);
	derror = abs(p1.y - p0.y) * 2;
	error = 0;
	x = p0.x;
	y = p0.y;
	while (x <= p1.x)
	{
		if (flip)
			drawpixel(y, x, wolf->buffer, color);
		else
			drawpixel(x, y, wolf->buffer, color);
		error += derror;
		if (error > p1.x - p0.x)
		{
			if (p1.y > p0.y)
				y += 1;
			else
				y += -1;
			error -= (p1.x - p0.x) * 2;
		}
		x++;
	}
}

/*
*	Calculates points on the border of the circle in its first octant,
*	rest are determined by symmetry. draw unique points until (x = y)
*	choosing points closest to the radius of the circle.
*/
void		draw_circle(t_app *wolf, t_point p, int r, int color)
{
	int x;
	int y;
	int d;

	x = r;
	y = 0;
	d = 1 - r;
	while (x >= y)
	{
		drawpixel(p.x + x, p.y + y, wolf->buffer, color);
		drawpixel(p.x - x, p.y + y, wolf->buffer, color);
		drawpixel(p.x + x, p.y - y, wolf->buffer, color);
		drawpixel(p.x - x, p.y - y, wolf->buffer, color);
		drawpixel(p.x + y, p.y + x, wolf->buffer, color);
		drawpixel(p.x - y, p.y + x, wolf->buffer, color);
		drawpixel(p.x + y, p.y - x, wolf->buffer, color);
		drawpixel(p.x - y, p.y - x, wolf->buffer, color);
		if (d < 0)
			d += (2 * ++y) + 1;
		else
		{
			x--;
			d += (2 * (++y - x)) + 1;
		}
	}
}

/*
*	Instead of drawing individual pixels on symmetrical positions along the
*	circle's radius, we draw lines from one end to its opposite.
*/
void		draw_filled_circle(t_app *wolf, t_point p, int r, int color)
{
	int x;
	int y;
	int d;

	x = r;
	y = 0;
	d = 1 - r;
	while (x >= y)
	{
		draw_line(wolf, (t_point){p.x + x, p.y + y}, (t_point){p.x - x, p.y + y}, color);
		draw_line(wolf, (t_point){p.x + x, p.y - y}, (t_point){p.x - x, p.y - y}, color);
		draw_line(wolf, (t_point){p.x + y, p.y + x}, (t_point){p.x - y, p.y + x}, color);
		draw_line(wolf, (t_point){p.x + y, p.y - x}, (t_point){p.x - y, p.y - x}, color);
		if (d < 0)
			d += (2 * ++y) + 1;
		else
		{
			x--;
			d += (2 * (++y - x)) + 1;
		}
	}
}