/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lerp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:04:30 by eniini            #+#    #+#             */
/*   Updated: 2020/11/22 20:11:47 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Lineal interpolation calculation using floating point values.
**	Handles precision differences between arguments by dividing
**	the multiplications between [p] and [a/b] in two parts.
*/

double	ft_d_lerp(double a, double b, double p)
{
	if (a == b)
		return (a);
	if (p == 1)
		return (b);
	if (!(p))
		return (a);
	return (a * (1.0f - p)) + (b * p);
}
