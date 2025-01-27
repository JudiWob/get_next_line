/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:28:54 by jpaselt           #+#    #+#             */
/*   Updated: 2025/01/27 17:29:44 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*leftover(char **leftovers, char *result)
{
	ssize_t	len;
	ssize_t	i;

	i = nl_check(result);
	len = s_len(&result[i]);
	if (len == 0)
	{
		return (result);
	}
	*leftovers = malloc(len + 1);
	if (!*leftovers)
		return (NULL);
	s_cpy(*leftovers, &result[i]);
	(result)[i] = '\0';
	return (result);
}

char	*read_save(int fd, char **buffer, int *bytesread, char **result)
{
	*bytesread = read(fd, *buffer, BUFFER_SIZE);
	if (*bytesread == 0 && (*result)[0] == '\0')
	{
		free(*result);
		*result = NULL;
		free(*buffer);
		return (*result);
	}
	if (*bytesread == 0)
		return (free(*buffer),*result);
	(*buffer)[*bytesread] = '\0';
	join(result, *buffer);
	return (*result); // kann NULL sein wenn join failed
}

char	*get_next_line(int fd)
{
	int			bytesread;
	char		*buffer;
	char		*result;
	static char	*leftovers;

	result = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		if (leftovers)
		{
			free(leftovers);
			leftovers = NULL;
		}
		return (result);
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (result);
	buffer[BUFFER_SIZE] = '\0';
	if (!duplicate(&result, &leftovers))
		return (result);
	while (nl_check(result) == 0)
		if (!read_save(fd, &buffer, &bytesread, &result) || bytesread == 0)
			return (result); // return NULL malloc fail
	return (free (buffer), leftover(&leftovers, result));
}

// int main()
// {
// 	int fd;
// 	char	*rescpy = NULL;

// 	fd = open("text.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("error reading file");
// 		return (0);
// 	}

//     rescpy = get_next_line(fd);
//     printf("Result0: %s\n", rescpy);
//     free(rescpy);

// 	rescpy = get_next_line(fd);
//     printf("Result 1: %s\n", rescpy);
// 	free(rescpy);

// 	rescpy = get_next_line(fd);
//     printf("Result 2: %s\n", rescpy);
//     free(rescpy);

// 	rescpy = get_next_line(fd);
//     printf("Result 3: %s\n", rescpy);
//     free(rescpy);

// 	rescpy = get_next_line(fd);
//     printf("Result 4: %s\n", rescpy);
//     free(rescpy);

// 	rescpy = get_next_line(fd);
//     printf("Result 5: %s\n", rescpy);
//     free(rescpy);
// 	return (0);
// }
