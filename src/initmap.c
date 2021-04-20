/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:54:43 by alero             #+#    #+#             */
/*   Updated: 2021/04/20 10:55:11 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

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
	s->map = (char **)malloc(sizeof(char *) * s->y);
	while(i <= s->y)
	{
		s->map[i] = (char *)malloc(sizeof(char *) * s->x);
		ft_bzero(s->map[i], s->x);
		s->map[i][s->x] = '\0';
		i++;
	}
	s->map[s->y][0] = '\0';
//	ft_memset(s->map, 0, sizeof(char *) * s->y * s->x);
	ft_strclr(s->map[s->y]);
	return(0);
}
