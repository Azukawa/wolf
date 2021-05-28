/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:00:19 by alero             #+#    #+#             */
/*   Updated: 2021/05/27 17:26:33 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		drawplayer(t_app *app, t_map_player *player)
{
			t_point		point;
			point.x = (int)player->p.x;
			point.y = (int)player->p.y;
			draw_circle(app, point, 10, 0xff0000);
			draw_circle(app, point, 5, 0xff0000);

}
