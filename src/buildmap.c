/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:55:25 by alero             #+#    #+#             */
/*   Updated: 2021/06/21 18:51:19 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
 *	Simple mother function for
 *	commanding the seperate map
 *	reading functions.
 *	final 2d char will be map[y][x]
 */

static int	ismap(char *str)
{
	int	i;
	int	x;

	i = ft_strlen(str) - 4;
	x = ft_strcmp(str + i, ".map");
	if (x != 0)
		return (-1);
	return (1);
}

int	buildmap(char *str, t_map *s)
{	
	int	x;

	s->w = 0;
	x = ismap(str);
	if (x == -1)
		return (-1);
	x = checkmap(str, s);
	if (x == -1)
		return (-1);
	initmap(s);
	readmap(str, s);
	return (1);
}
