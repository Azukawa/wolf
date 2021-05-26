/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawpixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:00:27 by alero             #+#    #+#             */
/*   Updated: 2021/05/25 18:36:06 by eniini           ###   ########.fr       */
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
		buffer[i] = color;
}
