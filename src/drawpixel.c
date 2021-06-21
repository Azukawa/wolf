/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawpixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:00:27 by alero             #+#    #+#             */
/*   Updated: 2021/06/21 19:07:45 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
*	since both buffer and color are ARGB8888, no additional casting is required.
*/
void	drawpixel(int x, int y, uint32_t *buffer, uint32_t color)
{
	uint32_t	i;

	i = (SCREEN_WIDTH * y) + x;
	if (x < SCREEN_WIDTH && y < SCREEN_HEIGHT && x >= 0 && y >= 0)
		buffer[i] = color;
}
