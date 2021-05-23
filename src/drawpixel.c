/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawpixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:00:27 by alero             #+#    #+#             */
/*   Updated: 2021/05/23 16:54:19 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

//todo check if color should be unsigned int
//todo check endian for correct colors
void		drawpixel(int x, int y, unsigned int *buffer, int color)
{
	uint32_t	i;
	i = (x + SCREEN_WIDTH * y);
	if (x < SCREEN_WIDTH && y < SCREEN_HEIGHT &&  x >= 0 && y >= 0)
	{
		//unsigned int *dst;

		//dst = (unsigned int *)buffer + i;
		//*dst = color;
		//buffer[0 + i] = (color >> 24);
		//buffer[1 + i] = (color) & 0xFF;
		//buffer[2 + i] = (color >> 8) & 0xFF;
		//buffer[3 + i] = (color >> 16) & 0xFF;
		buffer[i] = color;
		//ft_printf("%d\n", buffer[i]);
	}
}
