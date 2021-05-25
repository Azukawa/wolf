/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:01:28 by alero             #+#    #+#             */
/*   Updated: 2021/05/25 16:45:43 by alero            ###   ########.fr       */
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
	ft_clamp_d(start.x, 0, SCREEN_WIDTH);
	ft_clamp_d(start.y, 0, SCREEN_HEIGHT);
	ft_clamp_d(end.x, start.x, SCREEN_WIDTH);
	ft_clamp_d(end.y, start.y, SCREEN_HEIGHT);
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
	color = 0xFFFFFF00;
//	start.x = start.y = 100;
//	end.x = 150;
//	end.y = 200;
	square_x = SCREEN_WIDTH / map->w;
	square_y = SCREEN_HEIGHT / map->h;

	if(map)
	{	
		while (y < map->h)
		{
			while (x < map->w)
			{
				if(map->map[y][x] == '0')	
					color = 0xFFFFFF00;
				else
					color = 0x00000000;
				start.x = x * square_x;
				start.y = y * square_y;
				end.x = (x + 1) * square_x;
				end.y = (y + 1) * square_y;
				drawsquare(start, end, app->buffer, color);
				x++;
			}
			y++;
			x = 0;
		}
	}
}

