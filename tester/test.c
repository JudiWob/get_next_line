#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include <stdarg.h>
#include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

#include "get_next_line.h"

static void free_all(char * str);

int main()
{
	int test = open("giant_line.txt", O_RDWR);
	// int test = open("test", O_RDWR);
	// int test = open("test", O_RDWR);
	char *buffer;
	printf("1------------------\n");
	buffer = get_next_line(test);
	if (buffer != NULL)
		printf("%s\n",buffer);
	free_all(buffer);
	printf("2------------------\n");
	buffer = get_next_line(test);
	if (buffer != NULL)
		printf("%s\n",buffer);
	free_all(buffer);
	printf("3------------------\n");
	buffer = get_next_line(test);
	if (buffer != NULL)
		printf("%s\n",buffer);
	free_all(buffer);
	printf("4------------------\n");
	buffer = get_next_line(test);
	if (buffer != NULL)
		printf("%s\n",buffer);
	free_all(buffer);
	printf("5------------------\n");
	buffer = get_next_line(test);
	if (buffer != NULL)
		printf("%s\n",buffer);
	free_all(buffer);
	printf("6------------------\n");
	buffer = get_next_line(test);
	if (buffer != NULL)
		printf("%s\n",buffer);
	free_all(buffer);
	printf("7------------------\n");
	buffer = get_next_line(test);
	if (buffer != NULL)
		printf("%s\n",buffer);
	free_all(buffer);
	printf("8------------------\n");
	buffer = get_next_line(test);
	if (buffer != NULL)
		printf("%s\n",buffer);
	free_all(buffer);
	printf("9------------------\n");
	buffer = get_next_line(test);
	if (buffer != NULL)
		printf("%s\n",buffer);
	free_all(buffer);
	printf("10------------------\n");
	buffer = get_next_line(test);
	if (buffer != NULL)
		printf("%s\n",buffer);
	free_all(buffer);
	printf("11------------------\n");
	buffer = get_next_line(test);
	if (buffer != NULL)
		printf("%s\n",buffer);
	free_all(buffer);
	printf("12------------------\n");
	buffer = get_next_line(test);
	if (buffer != NULL)
		printf("%s\n",buffer);
	free_all(buffer);
	printf("13------------------\n");
	buffer = get_next_line(test);
	if (buffer != NULL)
		printf("%s\n",buffer);
	free_all(buffer);
	printf("14------------------\n");
	buffer = get_next_line(test);
	if (buffer != NULL)
		printf("%s\n",buffer);
	free_all(buffer);
	printf("15----------------\n");
		buffer = get_next_line(test);
	if (buffer != NULL)
		printf("%s\n",buffer);
	free_all(buffer);
	printf("16------------------\n");
	buffer = get_next_line(test);
	if (buffer != NULL)
		printf("%s\n",buffer);
	free_all(buffer);
	printf("17------------------\n");
	buffer = get_next_line(test);
	if (buffer != NULL)
		printf("%s\n",buffer);
	free_all(buffer);
	printf("18------------------\n");
	buffer = get_next_line(test);
	if (buffer != NULL)
		printf("%s\n",buffer);
	free_all(buffer);
	printf("19------------------\n");
	buffer = get_next_line(test);
	if (buffer != NULL)
		printf("%s\n",buffer);
	free_all(buffer);
	printf("20----------------\n");
		buffer = get_next_line(test);
	if (buffer != NULL)
		printf("%s\n",buffer);
	free_all(buffer);

// 	int i = 0;
// 	int counter = 0;
// {
// 	// while (buffer[i] != 'i')
// 	// {
// 		counter = read(test, &buffer[i], 2);
// 	// 	i++;
// 	// }
// 	printf("%s\n", buffer);
// 	printf("%d\n", counter);
// }
// {
// 			counter = read(test, &buffer[i], 9);
// 	// 	i++;
// 	// }
// 	printf("%s\n", buffer);
// 	printf("%d\n", counter);
	close(test);
// }
}

static void free_all(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
}
// char *get_next_line(int file)
// {
// 	char	buffer[BUFFER_SIZE];
// 	int		i;
// 	int		y;
// 	int		counter;
// 	char	*dest;

// 	i = 0;
// 	y = 0;
// 	counter = 0;
// 	while (i < BUFFER_SIZE)
// 	{
// 		counter += read(file, &buffer[i], 1);
// 		if (buffer[i] == '\n')
// 			break;
// 		i++;
// 	}
// 	dest = malloc(counter + 1);
// 	dest[counter] = '\0';
// 	while (y < counter)
// 	{
// 		dest[y] = buffer[y];
// 		y++;
// 	}
// return (dest);
// }
