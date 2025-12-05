/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnadais- <gnadais-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:07:55 by gnadais-          #+#    #+#             */
/*   Updated: 2025/12/05 14:07:58 by gnadais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *str);
int		find_newline(char *str);
char	*str_nappend(char *str1, char *str2, int n);
char	*create_line(char *str, int index);
char	*trim_leftover(char *str, int index);
char	*read_into_leftover(int fd, char *leftover);
char	*read_helper(int fd, char *leftover, char *buffer, int *bytes_read);

char	*get_next_line(int fd);

#endif
