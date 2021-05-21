/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:01:28 by alero             #+#    #+#             */
/*   Updated: 2021/04/20 13:10:07 by alero            ###   ########.fr       */
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
				drawpixel(x, y, app->buffer, 0xFFFFFF);
			else
				drawpixel(x, y, app->buffer, 0x000000);
			x++;
		}
		x = 0;
		y++;
	}
}
