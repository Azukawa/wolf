/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:00:28 by eniini            #+#    #+#             */
/*   Updated: 2021/04/20 14:07:11 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_clamp_i(int value, int min, int max)
{
	int	i;

	if (value < min)
		i = min;
	else
		i = value;
	if (i > max)
		return (max);
	else
		return (i);
}
