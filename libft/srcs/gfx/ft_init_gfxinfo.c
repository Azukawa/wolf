/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_gfxinfo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 14:03:51 by eniini            #+#    #+#             */
/*   Updated: 2021/05/22 17:08:18 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gfx.h"
#include <string.h>
#include <errno.h>
#include <unistd.h>

t_gfxinfo	*ft_init_1d_info(int win_w, int win_h, int bpp, char *addr)
{
	t_gfxinfo	*info;

	info = malloc(sizeof(t_gfxinfo));
	if (!info)
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		return (NULL);
	}
	info->win_width = win_w;
	info->win_height = win_h;
	info->bpp = bpp;
	info->one_d_addr = addr;
	info->two_d_addr = NULL;
	return (info);
}

t_gfxinfo	*ft_init_2d_info(int win_w, int win_h, int bpp, char **addr)
{
	t_gfxinfo	*info;

	info = malloc(sizeof(t_gfxinfo));
	if (!info)
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		return (NULL);
	}
	info->win_width = win_w;
	info->win_height = win_h;
	info->bpp = bpp;
	info->one_d_addr = NULL;
	info->two_d_addr = addr;
	return (info);
}
