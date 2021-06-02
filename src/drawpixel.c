/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawpixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:00:27 by alero             #+#    #+#             */
/*   Updated: 2021/05/28 21:51:52 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

//todo check if color should be unsigned int
//todo check endian for correct colors
void		drawpixel(int x, int y, uint32_t *buffer, uint32_t color)
{
	uint32_t	i;
	i = (SCREEN_WIDTH * y) + x;
	if (x < SCREEN_WIDTH && y < SCREEN_HEIGHT &&  x >= 0 && y >= 0)
	{
		buffer[i] = color;
		//uint8_t a = color >> 24 & 255;
		//uint8_t r = color >> 16 & 255;
		//uint8_t g = color >> 8 & 255;
		//uint8_t b = color & 255;
		//uint8_t v = (r + g + b) / 3;
		//buffer[i] = (255 << 24) | (v << 16) | (v << 8) | v;
		//buffer[i] = (color << 24 | color << 16 | color << 8 | color);
	}
	//buffer[i] = (color &  255);
	//buffer[i] = (color >> 8) & 255;
	//buffer[i] = (color >> 16) & 255;
	//buffer[i] = (color >> 24) & 255;
}
