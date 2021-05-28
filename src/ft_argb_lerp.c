/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argb_lerp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 22:04:11 by eniini            #+#    #+#             */
/*   Updated: 2021/05/28 22:04:20 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

uint32_t	ft_argb_lerp(uint32_t c1, uint32_t c2, double p)
{
	int a;
	int r;
	int g;
	int b;

	if (c1 == c2)
		return (c1);
	p = ft_clamp_d(p, 0.0, 1.0);
	a = ft_i_lerp((c1 >> 24) & 255, (c2 >> 24) & 255, p);
	r = ft_i_lerp((c1 >> 16) & 255, (c2 >> 16) & 255, p);
	g = ft_i_lerp((c1 >> 8) & 255, (c2 >> 8) & 255, p);
	b = ft_i_lerp(c1 & 255, c2 & 255, p);
	return (a << 24 | r << 16 | g << 8 | b);
}
