/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnadais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 22:58:06 by gnadais-          #+#    #+#             */
/*   Updated: 2025/11/13 22:58:59 by gnadais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	char		buffer[BUFFER_SIZE];
	int			bytes_read;
	int			newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = read_into_leftover(fd, leftover);
	if (!leftover)
		return (NULL);
	newline = find_newline(leftover);
	line = get_line(leftover, newline);
	leftover = trim_leftover(leftover, newline);
	return (line);
}

char	*read_into_leftover(int fd, char *leftover)
{
	char	*buffer;
	int		bytes_read;
	
	buffer = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while (find_newline(leftover) == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		leftover = str_nappend(leftover, buffer, bytes_read);
		if (!leftover)
			return (NULL);
	}
	free(buffer);
	return (leftover);
}

	
