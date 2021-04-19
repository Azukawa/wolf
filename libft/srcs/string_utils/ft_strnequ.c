/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 20:29:42 by eniini            #+#    #+#             */
/*   Updated: 2020/07/13 16:54:51 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;
	size_t j;

	if (s1 && s2)
	{
		i = 0;
		j = 0;
		while (j < n)
		{
			if (s1[i] != '\0' || s2[i] != '\0')
			{
				if ((unsigned char)s1[i] > (unsigned char)s2[i])
					return (0);
				if ((unsigned char)s1[i] < (unsigned char)s2[i])
					return (0);
				else
					i++;
			}
			j++;
		}
	}
	return (1);
}
