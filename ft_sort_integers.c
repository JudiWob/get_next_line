/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:48:03 by jpaselt           #+#    #+#             */
/*   Updated: 2024/11/08 15:52:28 by jpaselt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void ft_sort_arr(int *arr, int size);

void ft_sort_arr(int *arr, int size)
{
	int i = 0;
	int j = 0;
	int max_index = 0;
	
	int temp = arr[i];

	while(i < size)
	{
		j = i + 1;
		while(j < size)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int main(void)
{
	int i = 0;
	int size = 10;
	int arr[10] = {5, 2, 3, 1, 6, 10, 100, 0, -3 ,0};
	
	ft_sort_arr(arr, size);
	
	while (i < size)
	{
		printf("%d\n", arr[i]);
		i++;	
	}
}