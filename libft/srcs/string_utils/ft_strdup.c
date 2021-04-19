/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 13:19:21 by eniini            #+#    #+#             */
/*   Updated: 2020/10/16 09:17:28 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	allocates sufficient memory for a copy of the string [s1], does the copy,
**	and returns a pointer to it. If malloc fails, NULL is returned.
*/

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	i;

	i = ft_strlen(s1);
	if (!(dup = (char*)malloc(sizeof(dup) * (i + 1))))
		return (NULL);
	dup = ft_strcpy(dup, s1);
	return (dup);
}
