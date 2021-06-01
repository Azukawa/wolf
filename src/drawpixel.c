/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawpixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:00:27 by alero             #+#    #+#             */
/*   Updated: 2021/06/01 15:35:14 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

/*
*	Calculates the perceived brightness (luma) of a given color.
*/
uint32_t	argb_grayscale(uint32_t c)
{
	int8_t	a = c >> 24 & 255;
	uint8_t	r = c >> 16 & 255;
	uint8_t	g = c >> 8 & 255;
	uint8_t	b = c & 255;
	uint8_t	v = (0.2126 * r) + (0.7152 * g) + (0.0722 * b);
	return (a << 24) | (v << 16) | (v << 8) | v;
}

/*
*	Calculates 'truer', gamma-corrected perceived brightness of the given color.
*	Linearized values are weighed for their hue and added together, then
*	de-linearized back to sRGB space.
*/
uint32_t	argb_realgrayscale(uint32_t c)
{
	int8_t	a = c >> 24 & 255;
	uint8_t	r = c >> 16 & 255;
	uint8_t	g = c >> 8 & 255;
	uint8_t	b = c & 255;
	uint8_t result = pow(0.2126 * pow(r ,2.4) + 0.7152 * pow(g, 2.4) + 0.0722
		* pow(b, 2.4), 1 / 2.4);
	return (a << 24) | (result << 16) | (result << 8) | result;
}

	/*	Alternative solutions for more hue control:
	*	uint8_t a = color >> 24 & 255;
	*	uint8_t r = color >> 16 & 255;
	*	uint8_t g = color >> 8 & 255;
	*	uint8_t b = color & 255;
	*	buffer[i] = (a << 24 | r << 16 | g << 8 | b);
	*	OR
	*	buffer[i] = (color & 255);
	*	buffer[i] = (color >> 8) & 255;
	*	buffer[i] = (color >> 16) & 255;
	*	buffer[i] = (color >> 24) & 255;
	*/

void		drawpixel(int x, int y, uint32_t *buffer, uint32_t color)
{
	uint32_t	i;
	i = (SCREEN_WIDTH * y) + x;
	if (x < SCREEN_WIDTH && y < SCREEN_HEIGHT &&  x >= 0 && y >= 0)
		buffer[i] = color;
}

