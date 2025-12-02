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
	char		*leftcopy;
	int			lft_len;
	int			newline;

	lft_len = ft_strlen(leftover);
	leftcopy = leftover;
	if ((newline = find_newline(leftover, lft_len)) >= 0)
	{
		line = ft_strdup_len(leftover, newline + 1);
		leftover = ft_strdup_len(leftover + newline, left_len - newline);
		free(leftcopy);
		return (line);
	}
	line = ft_strdup_len(leftover, lft_len);
	if (!line)
		return (NULL);


	line = read_line(fd, leftover);
}

int	ft_strlen(char *str);
{
	int	i;

	i = 0;
	while (str++)
		i++;
	return (i);
}

char	*ft_strdup_len(char *str, int len)
{
	char	*dup;
	int		i;

	dup = (char *) malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (str)
	{
		dup[i] = *str[i];
		i++;
	}
	return (dup);
}

