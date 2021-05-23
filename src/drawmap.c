/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:01:28 by alero             #+#    #+#             */
/*   Updated: 2021/05/23 17:00:22 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		drawmap(t_map *map, t_app *app)
{	
	if (map->x == 0 || map->y == 0)
		return ;
	int	x, y, square_x, square_y;
	x = y = 0;
	square_x = SCREEN_WIDTH / (map->x - 1);
	square_y = SCREEN_HEIGHT / (map->y - 1);
	printf("mapx=%d\nmapy=%d\n", map->x, map->y);
	while(y < SCREEN_HEIGHT)
	{	
		while(x < SCREEN_WIDTH)
		{
			if (map->map[y / square_y][ x / square_x] == '0')
				drawpixel(x, y, app->buffer, 0xFFFFFF00);
			else
				drawpixel(x, y, app->buffer, 0x00000000);
			x++;
		}
		x = 0;
		y++;
	}
}
