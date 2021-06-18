/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:53:13 by alero             #+#    #+#             */
/*   Updated: 2021/06/18 18:31:56 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
 *	The first read of map file.
 *	This function determines map.x and map.y.
 *	Y rows are counted by gnl,
 *	X is counted by the nro ',' on the row.
 */
int	checkmap(char *str, t_map *s)
{
	int		fd;
	int		ret;
	int		i;
	int		wcount;
	char	*output;

	i = 0;
	output = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	ret = get_next_line(fd, &output);
	while (ret)
	{
		wcount = ft_wordcount(output, ',');
		if (wcount > s->w)
			s->w = wcount;
		i++;
		free(output);
		ret = get_next_line(fd, &output);
	}
	s->h = i;
	return (1);
}
