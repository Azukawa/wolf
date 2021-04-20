/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:52:01 by alero             #+#    #+#             */
/*   Updated: 2021/04/20 13:11:54 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

/*
 *	The second redthrough of map file.
 *	Goes through file line by line,
 *	and builds final array with
 *	linetogrid()
 */
int			readmap(char *str, t_map *s)
{
	int		fd;
	int		ret;
	int		i;
	char*	output;

	i = 0;
	
	if ((fd = open(str, O_RDONLY)) == -1)
		return(0);
	while ((ret = get_next_line(fd, &output)) > 0)
	{
		s->map[i] = linetogrid(s->map[i], output, s->x);
		i++;
		free(output);
	}
//	free(output);
	return(1);

}
