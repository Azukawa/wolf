/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inverse_i_lerp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:42:12 by eniini            #+#    #+#             */
/*   Updated: 2020/11/22 20:11:54 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Calculates the distance of [x] in a vector [ab] as a percentage.
*/

double	ft_inverse_i_lerp(int a, int b, int x)
{
	double placement;
	double distance;

	placement = x - a;
	distance = b - a;
	return ((distance == 0) ? 1.0 : (placement / distance));
}
