/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 16:21:30 by eniini            #+#    #+#             */
/*   Updated: 2021/03/10 13:00:22 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns a fresh valid string representing the integer [n] given as argument.
**	If the allocation fails, the function returns NULL.
*/

static int	get_len(intmax_t n)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(intmax_t n)
{
	char	*s;
	int		len;

	if (n == INTMAX_MIN)
	{
		if (!(s = ft_strdup("-9223372036854775808")))
			return (NULL);
		return (s);
	}
	len = get_len(n);
	if (!(s = ft_strnew(len)))
		return (NULL);
	if (n < 0)
		s[0] = '-';
	n = (n < 0) ? -n : n;
	while (1)
	{
		s[--len] = (n % 10) + '0';
		if ((n /= 10) == 0)
			break ;
	}
	return (s);
}
