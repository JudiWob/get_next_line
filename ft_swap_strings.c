/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_strings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:09:55 by jpaselt           #+#    #+#             */
/*   Updated: 2024/11/08 14:29:05 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(int argc, char **argv)
{
	char *temp;

	if (argc == 1)
		return(0);

	printf("1: %s\n", argv[1]);
	printf("2: %s\n", argv[2]);

	temp = argv[1];
	argv[1] = argv[2];
	argv[2] = temp;

	
	printf("1: %s\n", argv[1]);
	printf("2: %s\n", argv[2]);
}