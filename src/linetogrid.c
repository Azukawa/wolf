/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linetogrid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:49:59 by alero             #+#    #+#             */
/*   Updated: 2021/06/18 18:33:27 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
 *	Skips ',' and ' ' characters,
 *	puts rest to ret, up to x(max widht of map)
 */
char	*linetogrid(char *ret, char *out, int x)
{
	int	a;
	int	i;

	i = 0;
	a = 0;
	if (ret == NULL || out == NULL)
		return (0);
	while (i < x && out[a] != '\0')
	{
		if (out[a] != ',' && out[a] != ' ' )
		{
			ret[i] = out[a];
			i++;
		}
		a++;
	}
	ret[i] = '\0';
	return (ret);
}
