/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 13:48:02 by esukava           #+#    #+#             */
/*   Updated: 2021/03/29 17:56:28 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void *str;

	if (!(str = malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(str, size);
	return ((void*)str);
}
