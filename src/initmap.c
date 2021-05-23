/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:54:43 by alero             #+#    #+#             */
/*   Updated: 2021/05/23 17:26:54 by eniini           ###   ########.fr       */
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
	s->map = (char **)malloc(sizeof(char *) * (s->y + 1));
	while(i <= s->y)
	{
		s->map[i] = (char *)malloc(sizeof(char) * (s->x) + 1); //9 bytes from this are lost somewhere
		ft_bzero(s->map[i], s->x + 1);
		//s->map[i][s->x] = '\0';
		i++;
	}
	s->map[s->y] = NULL;
//	ft_memset(s->map, 0, sizeof(char *) * s->y * s->x);
//	ft_strclr(s->map[s->y]);
	return(0);
}
