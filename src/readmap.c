/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:52:01 by alero             #+#    #+#             */
/*   Updated: 2021/06/18 18:33:38 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
 *	The second redthrough of map file.
 *	Goes through file line by line,
 *	and builds final array with
 *	linetogrid()
 */
int	readmap(char *str, t_map *s)
{
	int		fd;
	int		ret;
	int		i;
	char	*output;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	ret = get_next_line(fd, &output);
	while (ret > 0)
	{
		s->map[i] = linetogrid(s->map[i], output, s->w);
		i++;
		free(output);
		ret = get_next_line(fd, &output);
	}
	return (1);
}
