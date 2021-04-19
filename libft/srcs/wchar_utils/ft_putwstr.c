/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:03:28 by eniini            #+#    #+#             */
/*   Updated: 2021/03/29 10:58:08 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Writes the wide string [wstr] into file descriptor [fd].
**	As wstrings have variable length, we have to write them one at a time.
*/

void		ft_putwstr(wchar_t *wstr, int fd)
{
	int		len;

	len = ft_wstrlen(wstr);
	while ((len -= ft_wcharlen((wint_t)(*wstr))) >= 0)
		ft_putwchar((wint_t)(*wstr++), fd);
}