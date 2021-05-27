/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:00:19 by alero             #+#    #+#             */
/*   Updated: 2021/05/27 15:00:46 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		drawplayer(t_app *app, t_player *player)
{
			t_point		point;
			point.x = (int)player->p.x;
			point.y = (int)player->p.y;
			draw_circle(app, point, 10, 0xff0000);
			draw_circle(app, point, 5, 0xff0000);

}
