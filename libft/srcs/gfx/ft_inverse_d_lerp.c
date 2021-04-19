/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inverse_d_lerp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:46:03 by eniini            #+#    #+#             */
/*   Updated: 2020/11/22 20:11:59 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Calculates the distance of [x] in a vector [ab] as a percentage.
*/

double	ft_inverse_d_lerp(double a, double b, double x)
{
	if (b - a == 0)
		return (1.0);
	if (x == a || x == b)
		return (0.0);
	return ((x - a) / (b - a));
}
