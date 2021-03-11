/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 11:43:24 by esukava           #+#    #+#             */
/*   Updated: 2021/02/11 18:36:57 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int			len;
	char		*rslt;

	len = ft_len(n);
	if (!(rslt = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	rslt[len--] = '\0';
	if (n == -2147483648)
		return ("-2147483648");
	if (n < 0)
	{
		n = n * -1;
		rslt[0] = '-';
	}
	else
		rslt[0] = '+';
	while ((rslt[0] == '-' && len >= 1) || (rslt[0] == '+' && len >= 0))
	{
		rslt[len--] = '0' + (n % 10);
		n = n / 10;
	}
	return (rslt);
}
