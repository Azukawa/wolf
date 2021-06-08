/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:54:46 by alero             #+#    #+#             */
/*   Updated: 2021/06/08 11:14:34 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

/*
 *		This function keeps track of how many times
 *		the loop goes through in a second, and outputs
 *		result to standard output.
 *		What happens when size_t seconds have passed
 *		is still unsure.
 *		printf("seconds from start = %ld\nfps = %d\n", sec, i);
 */
void	fps_counter(t_app *app)
{
	static int		i;
	static size_t	sec;
	static size_t	presec;

	sec = clock() / CLOCKS_PER_SEC;
	if (sec == presec)
	{
		i++;
	}
	else
	{
		ft_printf("[fps:%d] PLAYER:[angle:%.0lf][x:%.1lf][y:%.1lf]\n", i,
			app->player.angle, app->player.pos_x, app->player.pos_y);
		presec = sec;
		i = 0;
	}	
}
