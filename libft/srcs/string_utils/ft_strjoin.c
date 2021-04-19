/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:29:24 by eniini            #+#    #+#             */
/*   Updated: 2020/10/16 09:17:59 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	char	*bookmark;

	if (!s1 && !s2)
		return (NULL);
	if (!(concat = (char*)malloc(sizeof(char) * (ft_strlen(s1) +
	ft_strlen(s2) + 1))))
		return (NULL);
	bookmark = concat;
	while (*s1 != '\0')
		*(concat++) = *(s1++);
	while (*s2 != '\0')
		*(concat++) = *(s2++);
	*(concat) = '\0';
	return (bookmark);
}
