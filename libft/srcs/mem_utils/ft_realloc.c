/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 19:14:23 by eniini            #+#    #+#             */
/*   Updated: 2020/10/16 09:15:51 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	(This implementation does not emulate official version's capability
**	to resize previously created heap memory!)
**
**	If ptr is NULL, then the call is equivalent to malloc(size);
**	if size is equal to zero and ptr is not NULL,
**	then the call is equivalent to free(ptr).
**
**	Realloc() returns a pointer to the newly allocated memory,
**	or NULL if the request fails. If size was equal to 0, NULL is returned.
**	If realloc() fails the original block is left untouched.
*/

void	*ft_realloc(void *ptr, size_t size)
{
	void	*newptr;

	if (!ptr)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!(newptr = malloc(size)))
		return (NULL);
	if (!(ft_memcpy(newptr, ptr, size)))
		return (NULL);
	free(ptr);
	return (newptr);
}
