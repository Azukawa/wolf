/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 12:47:07 by esukava           #+#    #+#             */
/*   Updated: 2021/02/11 21:38:00 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define OUT  0
#define IN  1

int		ft_countwords(const char *s1, char c)
{
	int state;
	int wrds;

	wrds = 0;
	state = OUT;
	while (*s1)
	{
		if (*s1 == c)
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			wrds++;
		}
		s1++;
	}
	return (wrds);
}
