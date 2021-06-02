/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:55:25 by alero             #+#    #+#             */
/*   Updated: 2021/06/01 12:29:53 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

/*
 *	Simple mother function for
 *	commanding the seperate map
 *	reading functions.
 *	final 2d char will be map[y][x]
 */
int	buildmap(char *str, t_map *s)
{	
	if (str == NULL)
	{
		ft_printf("No path given, map building is skipped.\n");
		return (0);
	}
	checkmap(str, s);
	initmap(s);
	readmap(str, s);
	return (1);
}
