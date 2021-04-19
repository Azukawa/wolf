/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eniini <eniini@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 12:03:57 by eniini            #+#    #+#             */
/*   Updated: 2020/10/16 09:23:23 by eniini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	get_next_line reads an entire line minus its linebreak character from
**	given file descriptor (hereafter fd). Similarly to getline(3), program
**	calling this function is expected to free lines saved to given pointer.
**
**	First parameter is the fd that will be used to read.
**	Second parameter is the address of a pointer that will be used
**	to save the line read (minus the linebreak character) from fd.
**
**	The return value is 1/0/-1 depending on whether a line has been read, when
**	the reading has been completed, or if an error has happened respectively.
*/

#include <unistd.h>
#include "libft.h"

/*
**	soft FD limit. current system's soft cap can be checked with 'ulimit -n'
*/

#define FD_MAX 4096

/*
**	Increment str pointer until linebreak is found,
**	then copy that many bytes into *line and save rest back to *str.
**	If no line-break is found, all of the bytes saved to *str are
**	copied into *line.
*/

static int	getlinebreak(char **line, char **str)
{
	size_t		len;
	char		*temp;

	len = 0;
	while ((*str)[len] && (*str)[len] != '\n')
		len++;
	if ((*str)[len] == '\n')
	{
		if (!(*line = ft_strsub(*str, 0, len)))
			return (-1);
		if (!(temp = ft_strdup(*str + len + 1)))
			return (-1);
		free(*str);
		*str = temp;
	}
	else
	{
		if (!(*line = ft_strdup(*str)))
			return (-1);
		ft_strdel(str);
	}
	return (1);
}

/*
**	Safely combining read buffer with str[fd]
*/

static char	*getstr(const int fd, char **str, char *buffer)
{
	char		*temp;

	if (str[fd])
	{
		if (!(temp = ft_strjoin(str[fd], buffer)))
			return (NULL);
	}
	else
	{
		if (!(temp = ft_strdup(buffer)))
			return (NULL);
	}
	free(str[fd]);
	return (temp);
}

/*
**	Read and save buffers into str[fd] until linebreak or EOF is reached.
**	(str[fd] is always reallocated to hold previous saved data and new buffer)
**	In case of EOF, all stored buffers are given to getlinebreak function.
*/

int			get_next_line(const int fd, char **line)
{
	static char *str[FD_MAX];
	char		buffer[BUFF_SIZE + 1];
	ssize_t		readbytes;
	char		*temp;

	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	while ((readbytes = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[readbytes] = '\0';
		if (!(str[fd] = getstr(fd, str, buffer)))
			return (-1);
		if ((temp = ft_strchr(str[fd], '\n')))
			break ;
	}
	if (readbytes < 0)
		return (-1);
	else if (readbytes == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (getlinebreak(line, &str[fd]));
}
