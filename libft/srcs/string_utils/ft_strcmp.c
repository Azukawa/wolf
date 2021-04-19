/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 13:41:43 by eniini            #+#    #+#             */
/*   Updated: 2020/10/16 09:16:31 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Lexicographically compares the null-terminated strings [s1] and [s2].
**
**	Returns an integer greater than, equal to, or less than 0,
**	according as the [s1] is greater than, equal to, or less than the [s2].
**
**	Comparison is done with unsigned characters,
**	so that `\200' is greater than `\0'.
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (((unsigned char)s1[i] - (unsigned char)s2[i]));
}
