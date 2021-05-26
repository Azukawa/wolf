/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:01:28 by alero             #+#    #+#             */
/*   Updated: 2021/05/26 11:56:12 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

/*
 *		This funtion draws a square.
 *		The start point is the top left corner,
 *		and end point is the lower right corner.
 */
void		drawsquare(t_point start, t_point end, unsigned int *buffer, int color)
{
	int	x;

	x = start.x;

	while (start.y <= end.y)
	{	
		while (start.x <= end.x)
		{	
			drawpixel(start.x, start.y, buffer, color);
			start.x++;
		}
		start.y++;
		start.x = x;
	}

}

void		drawmap(t_map *map, t_app *app)
{
	t_point		start;
	t_point		end;
	int			color, square_x, square_y, x, y;

	x = y = 0;
	square_x = SCREEN_WIDTH / map->w;
	square_y = SCREEN_HEIGHT / map->h;

	if(map)
	{	
		while (y < map->h)
		{
			while (x < map->w)
			{
				if(map->map[y][x] == '0')
					color = 0xffffff;
				else
					color = 0;
				start.x = x * square_x;
				start.y = y * square_y;
				end.x = (x + 1) * square_x;
				end.y = (y + 1) * square_y;
				if (color != 0)
					drawsquare(start, end, app->buffer, ft_color_lerp(0x7f0055, ft_color_lerp(color, 0x7dff00, (float)x / map->w), (float)y / map->h));
				else
					drawsquare(start, end, app->buffer, 0);
				x++;
			}
			y++;
			x = 0;
		}
	}
}

