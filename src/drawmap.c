/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:01:28 by alero             #+#    #+#             */
/*   Updated: 2021/05/28 22:05:31 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

/*
 *		This funtion draws a square.
 *		The start point is the top left corner,
 *		and end point is the lower right corner.
 */
static void	drawsquare(t_point start, t_point end, unsigned int *buffer, uint32_t color)
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
	//int			color, 
	int			square_x, square_y, x, y;

	x = y = 0;
	square_x = (SCREEN_WIDTH / map->w) / 4;
	square_y = (SCREEN_HEIGHT / map->h) / 4;

	if(map)
	{	
		while (y < map->h)
		{
			while (x < map->w)
			{
				//if(map->map[y][x] == '0')
				//	color = 0xffffffff;
				//else
				//	color = 0xff;
				start.x = x * square_x;
				start.y = y * square_y;
				end.x = (x + 1) * square_x;
				end.y = (y + 1) * square_y;
				//if (color != 0)
				if(map->map[y][x] == '0')
					drawsquare(start, end, app->buffer, ft_argb_lerp(0xff7f0055, ft_argb_lerp(0xff, 0xff7dff00, (float)x / map->w), (float)y / map->h));
				//else
					//drawsquare(start, end, app->buffer, 0x0);
				x++;
			}
			y++;
			x = 0;
		}
	}
}

