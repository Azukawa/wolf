/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:53:13 by alero             #+#    #+#             */
/*   Updated: 2021/06/01 12:37:22 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

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
	char	*output;

	i = 0;
	output = NULL;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (0);
	while ((ret = get_next_line(fd, &output)) > 0)
	{
		if (ft_wordcount(output, ',') > (size_t)s->w)
			s->w = ft_wordcount(output, ',');
		i++;
		free(output);
	}
	s->h = i;
//	free(output);
	return (0);
}
