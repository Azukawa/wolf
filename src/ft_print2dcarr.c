/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2dcarr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:49:01 by alero             #+#    #+#             */
/*   Updated: 2021/05/21 15:16:53 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

/*
 *	Simple 2d char array printer using prinf
 */
void	ft_print2dcarr(char **arr)
{
	int i;
	i = 0;
	if (!arr)
		return ;
	while(arr[i] != NULL)
	{
		ft_printf("row%d =\t\t%s\n", i, arr[i]);
		i++;
	}
}
