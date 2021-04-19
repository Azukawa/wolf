/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 13:41:43 by eniini            #+#    #+#             */
/*   Updated: 2020/10/16 09:19:05 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Lexicographically compares compares not more than n characters in
**	the null-terminated strings [s1] and [s2].
**	Characters after '\0' are not compared.
**
**	Returns an integer greater than, equal to, or less than 0,
**	according as the [s1] is greater than, equal to, or less than the [s2].
**
**	Comparison is done with unsigned characters,
**	so that `\200' is greater than `\0'.
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (n > 1 && (s1[i] != '\0' && s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
		{
			i++;
			n--;
		}
		if (s1[i] != s2[i])
			break ;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
