/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:04:11 by eniini            #+#    #+#             */
/*   Updated: 2021/03/29 13:55:19 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns the byte length of a null-terminated wide string array
**	(not counting the null terminator itself).
**	wstrnlen returns the sum byte length of [n] characters of the wide string.
*/

size_t		ft_wstrnlen(wchar_t *wstr, size_t n)
{
	size_t	strlen;

	strlen = 0;
	while (*wstr != L'\0' && n)
	{
		strlen += ft_wcharlen((wint_t)(*wstr));
		n--;
		wstr++;
	}
	return (strlen);
}

size_t		ft_wstrlen(wchar_t *wstr)
{
	size_t	strlen;

	strlen = 0;
	while (*wstr != L'\0')
	{
		strlen += ft_wcharlen((wint_t)(*wstr));
		wstr++;
	}
	return (strlen);
}
