/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 12:58:03 by eniini            #+#    #+#             */
/*   Updated: 2020/10/16 09:16:07 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Appends a copy of the valid string [s2] to the end of the valid string [s1]
**	then adds a terminating `\0' and returns a pointer to it.
**	[s1] must have sufficient space to hold the result.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	s1len;
	size_t	i;

	s1len = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0')
	{
		s1[s1len + i] = s2[i];
		i++;
	}
	s1[s1len + i] = '\0';
	return (s1);
}
