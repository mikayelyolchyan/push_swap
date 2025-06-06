/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:48:43 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/06 22:17:21 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/push_swap.h"

static void	args_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(int *array, int args_count)
{
	int	i;
	int	j;

	i = 0;
	while (i < args_count - 1)
	{
		j = 0;
		while (j < args_count - i - 1)
		{
			if (array[j] > array[j + 1])
				args_swap(&array[j], &array[j + 1]);
			j++;
		}
		i++;
	}
}
