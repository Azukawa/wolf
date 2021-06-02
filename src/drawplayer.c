/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:00:19 by alero             #+#    #+#             */
/*   Updated: 2021/06/02 14:49:52 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		drawplayer(t_app *app, t_map_player *player, t_map *map)
{
			static	t_point		point;
			int			square_x, square_y;
			square_x = player->p.x * ((float)map->w / SCREEN_WIDTH);
			square_y = player->p.y * ((float)map->h / SCREEN_HEIGHT);
			ft_printf("square_x = %i\nsquare_y = %i\nmap->w = %i\n", square_x, square_y, map->w);
			
			if(map->map[square_y][square_x]== '0')
			{
				point.x = (int)player->p.x;
				point.y = (int)player->p.y;
				ft_printf("CLEAR\n");
			}
			else
			{
				player->p.x = point.x;
				player->p.y = point.y;

				ft_printf("COLLISION!\n");
			}
						

			draw_circle(app, point, 10, 0xff0000);
			draw_circle(app, point, 5, 0xff0000);

}
