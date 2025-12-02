/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnadais- <gnadais-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:24:21 by gnadais-          #+#    #+#             */
/*   Updated: 2025/12/02 13:25:20 by gnadais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_line(int fd, char *line, int *line_len, static char *leftover)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	int		newline;
	
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		newline = find_newline(buffer, bytes_read);
		*line_len += bytes_read;
		if (newline >= 0)
			return (newline + *line_len);
	}
	if (bytes_read == -1)
		return (-1);
}

int	find_newline(char *str, int	len)
{
	int	index;

	index = -1;
	while (++index < len)
	{
		if (str[index] == '\n')
			return (str);
	}
	return (-1);
}

char	*create_line(char *line, char *buffer, int newline)
