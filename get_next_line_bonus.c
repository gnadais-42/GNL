/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnadais- <gnadais-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:07:24 by gnadais-          #+#    #+#             */
/*   Updated: 2025/12/05 14:07:31 by gnadais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*fd_leftovers[4096];
	char		*leftover;
	char		*line;
	int			newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	leftover = fd_leftovers[fd];
	leftover = read_into_leftover(fd, leftover);
	if (!leftover)
	{
		fd_leftovers[fd] = NULL;
		return (NULL);
	}
	newline = find_newline(leftover);
	line = create_line(leftover, newline);
	leftover = trim_leftover(leftover, newline);
	fd_leftovers[fd] = leftover;
	return (line);
}

char	*read_into_leftover(int fd, char *leftover)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (find_newline(leftover) == -1)
	{
		leftover = read_helper(fd, leftover, buffer, &bytes_read);
		if (!leftover)
		{
			free(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
	}
	free(buffer);
	return (leftover);
}

char	*read_helper(int fd, char *leftover, char *buffer, int *bytes_read)
{
	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read == -1)
	{
		free(leftover);
		return (NULL);
	}
	if (*bytes_read == 0)
		return (leftover);
	buffer[*bytes_read] = '\0';
	return (str_nappend(leftover, buffer, *bytes_read));
}
