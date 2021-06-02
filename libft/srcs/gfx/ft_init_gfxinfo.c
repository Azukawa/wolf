/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_gfxinfo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 14:03:51 by eniini            #+#    #+#             */
/*   Updated: 2021/06/02 16:05:06 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gfx.h"
#include <string.h>
#include <errno.h>
#include <unistd.h>

t_gfxinfo	*ft_init_1d_info(int w, int h, int bpp, unsigned char *c)
{
	t_gfxinfo	*info;

	info = malloc(sizeof(t_gfxinfo));
	if (!info)
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		return (NULL);
	}
	info->img_width = w;
	info->img_height = h;
	info->bpp = bpp;
	info->one_d_addr = c;
	info->two_d_addr = NULL;
	return (info);
}

t_gfxinfo	*ft_init_2d_info(int w, int h, int bpp, unsigned char **c)
{
	t_gfxinfo	*info;

	info = malloc(sizeof(t_gfxinfo));
	if (!info)
	{
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		return (NULL);
	}
	info->img_width = w;
	info->img_height = h;
	info->bpp = bpp;
	info->one_d_addr = NULL;
	info->two_d_addr = c;
	return (info);
}
