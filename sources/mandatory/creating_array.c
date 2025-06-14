/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 19:06:16 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/14 15:12:03 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

static int	counting_numbers(int argc, char **argv)
{
	char	**tmp_array;
	int		i;
	int		j;
	int		total_numbers;

	total_numbers = 0;
	i = 1;
	while (i < argc)
	{
		tmp_array = ft_split(argv[i], ' ');
		if (!tmp_array)
			return (ft_printf("Error: ft_split failed\n"), 1);
		j = 0;
		while (tmp_array[j])
			j++;
		total_numbers += j;
		free_char_array(tmp_array);
		i++;
	}
	return (total_numbers);
}

static char	**fill_array(int argc, char **argv, char **array)
{
	int		index1;
	int		index2;
	int		i;
	char	**tmp_array;

	index1 = 0;
	i = 1;
	while (i < argc)
	{
		tmp_array = ft_split(argv[i], ' ');
		if (!tmp_array)
			return (free_char_array(array), \
				ft_printf("Error: ft_split failed\n"), NULL);
		index2 = 0;
		while (tmp_array[index2])
			array[index1++] = tmp_array[index2++];
		free(tmp_array);
		i++;
	}
	array[index1] = NULL;
	return (array);
}

char	**creating_char_array(int argc, char **argv, char **array)
{
	int	total_numbers;

	total_numbers = counting_numbers(argc, argv);
	array = malloc(sizeof(char *) * (total_numbers + 1));
	if (!array)
		return (ft_printf("Error: args_char_array malloc failed\n"), NULL);
	array = fill_array(argc, argv, array);
	if (array == NULL)
		return (NULL);
	return (array);
}

int	char_array_args_count(char	**array)
{
	int	index;

	index = 0;
	while (array[index] != NULL)
		index++;
	return (index);
}

int	*creating_int_array(int argc, char **argv, t_array *array)
{
	int		index;

	array->char_args_array = NULL;
	array->char_args_array = creating_char_array(argc, argv, \
								array->char_args_array);
	if (validity_check(array->char_args_array) == false)
		return (free_char_array(array->char_args_array), NULL);
	array->args_count = char_array_args_count(array->char_args_array);
	array->int_args_array = (int *)malloc(array->args_count * sizeof(int));
	if (!array->int_args_array)
		return (free_char_array(array->char_args_array), NULL);
	index = 0;
	while (index < array->args_count)
	{
		array->int_args_array[index] = ft_atoi(array->char_args_array[index]);
		index++;
	}
	free_char_array(array->char_args_array);
	return (array->int_args_array);
}
