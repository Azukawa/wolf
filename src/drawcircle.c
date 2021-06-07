/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawcircle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:39:14 by eniini            #+#    #+#             */
/*   Updated: 2021/06/04 18:39:00 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
*	Calculates points on the border of the circle in its first octant,
*	rest are determined by symmetry. draw unique points until (x = y)
*	choosing points closest to the radius of the circle.
*/
void	draw_circle(t_app *wolf, t_point p, int r, uint32_t color)
{
	int	x;
	int	y;
	int	d;

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
void	draw_filled_circle(t_app *wolf, t_point p, int r, uint32_t color)
{
	int	x;
	int	y;
	int	d;

	x = r;
	y = 0;
	d = 1 - r;
	while (x >= y)
	{
		draw_line(wolf, (t_point){p.x + x, p.y + y},
			(t_point){p.x - x, p.y + y}, color);
		draw_line(wolf, (t_point){p.x + x, p.y - y},
			(t_point){p.x - x, p.y - y}, color);
		draw_line(wolf, (t_point){p.x + y, p.y + x},
			(t_point){p.x - y, p.y + x}, color);
		draw_line(wolf, (t_point){p.x + y, p.y - x},
			(t_point){p.x - y, p.y - x}, color);
		if (d < 0)
			d += (2 * ++y) + 1;
		else
		{
			x--;
			d += (2 * (++y - x)) + 1;
		}
	}
}
