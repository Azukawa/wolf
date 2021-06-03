/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:54:46 by alero             #+#    #+#             */
/*   Updated: 2021/06/03 13:04:08 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

/*
 *		This function keeps track of how many times
 *		the loop goes through in a second, and outputs
 *		result to standard output.
 *		What happens when size_t seconds have passed
 *		is still unsure.
 *
 */
void	fps_counter(void)
{
	static int		i;
	static size_t	sec;
	static size_t	presec;

	sec = clock() / CLOCKS_PER_SEC;
	if (sec == presec)
	{
		i++;
	}
	else
	{
		printf("seconds from start = %ld\nfps = %d\n", sec, i);
		presec = sec;
		i = 0;
	}	
}
