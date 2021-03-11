/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi1000.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:20:08 by esukava           #+#    #+#             */
/*   Updated: 2020/10/28 17:23:50 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi1000(const char *str)
{
	int i;
	int res;
	int neg;

	i = 0;
	res = 0;
	neg = 0;
	while (ft_iswhite(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		neg++;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
		res = res * 10 + str[i++] - '0';
	if (neg > 0)
		res = res * -1;
	if (res > 1000)
		return (1000);
	if (res < -1000)
		return (-1000);
	return (res);
}
