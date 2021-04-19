/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 20:27:29 by eniini            #+#    #+#             */
/*   Updated: 2020/10/16 09:19:47 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;

	if (!(ret = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ret[size] = '\0';
	while (size--)
		ret[size] = '\0';
	return (ret);
}
