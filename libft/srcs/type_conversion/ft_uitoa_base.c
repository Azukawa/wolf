/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:15:39 by eniini            #+#    #+#             */
/*   Updated: 2021/03/15 10:15:53 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns a string representation of unsigned integer [ui] in base[x].
**	Bases over 36 and under 2 are not supported as they don't utilize
**	the same format.
*/

char	*ft_uitoa_base(size_t ui, int base, t_bool lcase)
{
	size_t	uix;
	int		i;
	char	*s;
	char	cval;

	if (base > 36 || base < 2)
		return (NULL);
	cval = (lcase) ? 'a' : 'A';
	uix = ui;
	i = 1;
	while (uix >= (unsigned int)base && i++)
		uix /= base;
	if (!(s = ft_strnew(i)))
		return (NULL);
	while (1)
	{
		s[--i] = ui % base >= 10 ? ui % base - 10 + cval : ui % base + '0';
		if ((ui /= base) == 0)
			break ;
	}
	return (s);
}
