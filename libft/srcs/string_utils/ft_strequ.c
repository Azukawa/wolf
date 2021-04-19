/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 20:28:49 by eniini            #+#    #+#             */
/*   Updated: 2020/07/13 16:54:18 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t i;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i] != '\0' || s2[i] != '\0')
		{
			if ((unsigned char)s1[i] > (unsigned char)s2[i])
				return (0);
			if ((unsigned char)s1[i] < (unsigned char)s2[i])
				return (0);
			else
				i++;
		}
	}
	return (1);
}
