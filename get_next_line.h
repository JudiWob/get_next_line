/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:16:57 by tsuno             #+#    #+#             */
/*   Updated: 2025/01/27 17:45:18 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

ssize_t	nl_check(char *s);
ssize_t	s_len(char *str);
void	s_cpy(char *dest, char *src);
char	*duplicate(char **result, char **s);
char	*join(char **result, char *buffer);
char	*get_next_line(int fd);

#endif