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

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (*str++)
		len++;
	return (len);
}

int	find_newline(char *str)
{
	int	index;

	if (!str)
		return (-1);
	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

char	*str_nappend(char *str1, char *str2, int n)
{
	char	*joined;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str1);
	joined = (char *) malloc (sizeof(char) * (len + n + 1));
	if (!joined)
	{
		free(str1);
		return (NULL);
	}
	i = -1;
	while (++i < len)
		joined[i] = str1[i];
	j = -1;
	while (++j < n && str2[j])
		joined[i + j] = str2[j];
	joined[i + j] = '\0';
	if (str1)
		free(str1);
	return (joined);
}

char	*get_line(char *str, int index)
{
	char	*line;
	int		i;

	if (!str || !*str)
		return (NULL);
	if (index == -1)
		index = ft_strlen(str) - 1;
	line = (char *) malloc(sizeof(char) * (index + 2));
	if (!line)
		return (NULL);
	i = -1;
	while (++i <= index)
		line[i] = str[i];
	line[i] = '\0';
	return (line);
}

char	*trim_leftover(char *str, int index)
{
	char	*trimmed;
	int		len;
	int		i;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (index == -1)
	{
		free(str);
		return (NULL);
	}
	trimmed = (char *) malloc(sizeof(char) * (len - index));
	if (!trimmed)
		return (NULL);
	i = -1;
	while (str[++i + index + 1])
		trimmed[i] = str[i + index + 1];
	trimmed[i] = '\0';
	free(str);
	return (trimmed);
}
