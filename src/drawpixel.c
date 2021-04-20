/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawpixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:00:27 by alero             #+#    #+#             */
/*   Updated: 2021/04/20 13:10:32 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

//todo check if color should be unsigned int
//todo check endian for correct colors
void		drawpixel(float x, float y, char *buffer, int color)
{
	int	i;
	i = ((int)x + SCREEN_WIDTH * (int)y) * 4;
	if (x < SCREEN_WIDTH && y < SCREEN_HEIGHT &&  x >= 0 && y >= 0)
	{
		buffer[0 + i] = (color >> 24);
		buffer[1 + i] = (color) & 0xFF;
		buffer[2 + i] = (color >> 8) & 0xFF;
		buffer[3 + i] = (color >> 16) & 0xFF;
	}
}
