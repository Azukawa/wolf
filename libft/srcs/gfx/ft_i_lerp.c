/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_lerp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:04:33 by eniini            #+#    #+#             */
/*   Updated: 2020/11/22 20:11:33 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Lineal interpolation calculation that returns an integer.
**	Cast to int is warranted as [p * (b - a)] returns a double due to coercion.
*/

int		ft_i_lerp(int a, int b, double p)
{
	return (a + (int)(p * (b - a)));
}
