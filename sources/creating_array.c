/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 19:06:16 by miyolchy          #+#    #+#             */
/*   Updated: 2025/05/31 19:06:40 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/push_swap.h"

static int	counting_numbers(int argc, char **argv)
{
	char	**args_chars_tmp_array;
	int		i;
	int		j;
	int		total_numbers;

	total_numbers = 0;
	i = 1;
    while (i < argc)
    {
        args_chars_tmp_array = ft_split(argv[i], ' ');
        if (!args_chars_tmp_array)
            return (ft_printf("Error: ft_split failed\n"), 1);
        j = 0;
        while (args_chars_tmp_array[j])
            j++;
        total_numbers += j;
        free_array(args_chars_tmp_array);
        i++;
    }
	return (total_numbers);
}

static char	**fill_array(int argc, char **argv, char **args_chars_array)
{
	int	index1;
	int	index2;
	int	i;
	char	**args_chars_tmp_array;
	
	index1 = 0;
    i = 1;
    while (i < argc)
    {
        args_chars_tmp_array = ft_split(argv[i], ' ');
        if (!args_chars_tmp_array)
        {
            free_array(args_chars_array);
            return (ft_printf("Error: ft_split failed\n"), NULL);
        }
        index2 = 0;
        while (args_chars_tmp_array[index2])
        {
            args_chars_array[index1] = args_chars_tmp_array[index2];
            index1++;
            index2++;
        }
        free(args_chars_tmp_array); // Освобождаем только массив, строки перенесены
        i++;
    }
    args_chars_array[index1] = NULL; // Завершаем массив NULL

	return (args_chars_array);
}

char	**creating_array(int argc, char **argv, char **args_chars_array)
{
	int	total_numbers;

	total_numbers = counting_numbers(argc, argv);

    // Выделяем память под массив всех чисел
    args_chars_array = malloc(sizeof(char *) * (total_numbers + 1));
    if (!args_chars_array)
        return (ft_printf("Error: args_chars_array malloc failed\n"), NULL);

    // Заполняем массив
    args_chars_array = fill_array(argc, argv, args_chars_array);
	if (args_chars_array == NULL)
		return (NULL);
	return (args_chars_array);
}
