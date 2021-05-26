/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:54:43 by alero             #+#    #+#             */
/*   Updated: 2021/05/25 16:58:30 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

/*
 *	Allocates 2d character array,
 *	based  on map.x and map.y.
 *	Each row is zeroed,
 *	terminators are placed.
 */
int		initmap(t_map *s)
{
	int i;
	i = 0;
	s->map = (char **)malloc(sizeof(char *) * (s->h + 1));
	while(i <= s->h)
	{
		s->map[i] = (char *)malloc(sizeof(char) * (s->w) + 1); //9 bytes from this are lost somewhere
		ft_bzero(s->map[i], s->w + 1);
		i++;
	}
	s->map[s->h] = NULL;
	return(0);
}
