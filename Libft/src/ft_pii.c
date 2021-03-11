/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pii.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:07:33 by alero             #+#    #+#             */
/*   Updated: 2021/03/08 17:13:42 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	this pii generating function is unstable when size gets big (> ~10000)
*/

static t_pii	ft_pii_pt2(t_pii pii)
{
	while (pii.i > -1)
	{
		pii.d = pii.d + pii.r[pii.i] * 10000;
		pii.b = 2 * pii.i - 1;
		pii.r[pii.i] = pii.d % pii.b;
		pii.d = pii.d / pii.b;
		pii.i--;
		if (pii.i == 0)
			break ;
		pii.d = pii.d * pii.i;
	}
	return (pii);
}

char			*ft_pii(int size)
{
	t_pii	pii;
	char	*a;
	char	*oldout;

	if (!(pii.r = (int *)ft_memalloc((size + 1) * sizeof(int))))
		return (NULL);
	pii.i = 0;
	pii.c = 0;
	pii.out = NULL;
	while (pii.i < size)
		pii.r[pii.i++] = 2000;
	pii.k = size;
	while (pii.k > 0)
	{
		pii.d = 0;
		pii.i = pii.k;
		pii = ft_pii_pt2(pii);
		a = ft_itoa(pii.c + pii.d / 10000);
		oldout = pii.out;
		pii.out = ft_strjoin(pii.out, a);
		pii.c = pii.d % 10000;
		pii.k = pii.k - 14;
	}
	return (pii.out);
}
