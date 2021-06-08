/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:01:28 by alero             #+#    #+#             */
/*   Updated: 2021/06/08 15:40:33 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

/*
 *		This funtion draws a square.
 *		The start point is the top left corner,
 *		and end point is the lower right corner.
 */
static void	drawsquare(t_point start, t_point end, unsigned int *buffer, \
		uint32_t color)
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

void	drawmap(t_map *map, t_app *app)
{
	t_point		start;
	t_point		end;
	t_point		square;
	t_point		index;

	ft_memset(&index, 0, sizeof(t_point));
	square.x = (SCREEN_WIDTH / map->w) / 4;
	square.y = (SCREEN_HEIGHT / map->h) / 4;
	while (index.y < map->h)
	{
		while (index.x < map->w)
		{
			start.x = index.x * square.x;
			start.y = index.y * square.y;
			end.x = (index.x + 1) * square.x;
			end.y = (index.y + 1) * square.y;
			if (map->map[index.y][index.x] == '0')
				drawsquare(start, end, app->buffer, \
ft_argb_lerp(0xff7f0055, ft_argb_lerp(0xff, 0xff7dff00, \
	(float)index.x / map->w), (float)index.y / map->h));
			index.x++;
		}
		index.y++;
		index.x = 0;
	}
}
