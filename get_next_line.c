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

char	*read_save(int fd, int *bytesread, char **result)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(*result);
		*result = NULL;
		return (*result);
	}
	buffer[BUFFER_SIZE] = '\0';
	*bytesread = read(fd, buffer, BUFFER_SIZE);
	if (*bytesread == 0 && (*result)[0] == '\0')
	{
		free(buffer);
		free(*result);
		*result = NULL;
		return (*result);
	}
	if (*bytesread == 0)
	{
		free(buffer);
		return (*result);
	}
	// buffer[*bytesread] = '\0';
	*result = join(result, buffer);
	return (free(buffer), *result); // kann NULL sein wenn join failed
}

char	*get_next_line(int fd)
{
	int			bytesread;
	char		*result;
	static char	*leftovers;

	if (!duplicate(&result, &leftovers))
		return (result); // return NULL malloc fail
	while (nl_check(result) == 0)
	{
		if (!read_save(fd, &bytesread, &result))
			return (result); // return NULL malloc fail
		if (bytesread == 0)
			return (result);
	}
	result = leftover(&leftovers, result);
	return (result);
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
// 	return (0);
// }
