/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:31:16 by jpaselt           #+#    #+#             */
/*   Updated: 2025/01/27 17:31:20 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*duplicate(char **result, char **leftovers)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = s_len(*leftovers);
	*result = malloc((len + 1));
	if (!*result)
		return (NULL);
	if (!*leftovers)
	{
		*result[0] = '\0';
		return (*result);
	}
	while ((*leftovers)[i])
	{
		(*result)[i] = (*leftovers)[i];
		i++;
	}
	result[0][i] = '\0';
	free(*leftovers);
	*leftovers = NULL;
	return (*result);
}

ssize_t	nl_check(char *s)
{
	ssize_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*join(char **result, char *buffer)
{
	char	*joined;

	joined = malloc(s_len(buffer) + s_len(*result) + 1);
	if (!joined)
	{
		free(*result);
		*result = NULL;
		return (*result);
	}
	s_cpy(joined, *result);
	s_cpy(&joined[s_len(*result)], buffer);
	free(*result);
	*result = joined;
	return (*result);
}

void	s_cpy(char *dest, char *src)
{
	ssize_t	i;

	i = 0;
	if (!src)
	{
		dest[i] = '\0';
		return ;
	}
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

ssize_t	s_len(char *str)
{
	ssize_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
