/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:12:29 by eniini            #+#    #+#             */
/*   Updated: 2021/05/26 15:41:56 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Initializing bunch of values in separate functions to appease Norminette.
**	Otherwise, just your typical fast line drawing algorithm implementation.
*/

#include "../include/wolf.h"

static void	init_startingvalues(t_point p0, t_point p1, int *x, int *y)
{
	x = p0.x;
	y = p0.y;
}

static void	init_errors(t_point p0, t_point p1, int *derror, int *error)
{
	derror = abs(p1.y - p0.y) * 2;
	error = 0;
}

static void	init_points(t_point p0, t_point p1, t_bool *flip)
{
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
}

/*
*	Line drawing algorithm between two point coordinates.
*	Initial checks make sure that drawing works for all angles into
*	every direction. After that, drawline() plots
*	a line of pixels from [point0] to [point1].
*/
void	draw_line(t_app *wolf, t_point p0, t_point p1, int color)
{
	int		derror;
	int		error;
	int		x;
	int		y;
	t_bool	flip;

	init_points(p0, p1, &flip);
	init_errors(p0, p1, &derror, &error);
	init_startingvalues(p0, p1, &x, &y);
	while (x <= p1.x && x++)
	{
		if (flip)
			drawpixel(y, x - 1, wolf->buffer, color);
		else
			drawpixel(x - 1, y, wolf->buffer, color);
		error += derror;
		if (error > p1.x - p0.x)
		{
			if (p1.y > p0.y)
				y += 1;
			else
				y += -1;
			error -= (p1.x - p0.x) * 2;
		}
	}
}
