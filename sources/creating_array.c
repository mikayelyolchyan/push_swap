/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 19:06:16 by miyolchy          #+#    #+#             */
/*   Updated: 2025/05/31 19:27:57 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/push_swap.h"

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
        free_array(tmp_array);
        i++;
    }
	return (total_numbers);
}

static char	**fill_array(int argc, char **argv, char **array)
{
	int	index1;
	int	index2;
	int	i;
	char	**tmp_array;
	
	index1 = 0;
    i = 1;
    while (i < argc)
    {
        tmp_array = ft_split(argv[i], ' ');
        if (!tmp_array)
        {
            free_array(array);
            return (ft_printf("Error: ft_split failed\n"), NULL);
        }
        index2 = 0;
        while (tmp_array[index2])
        {
            array[index1] = tmp_array[index2];
            index1++;
            index2++;
        }
        free(tmp_array); // Освобождаем только массив, строки перенесены
        i++;
    }
    array[index1] = NULL; // Завершаем массив NULL

	return (array);
}

char	**creating_array(int argc, char **argv, char **array)
{
	int	total_numbers;

	total_numbers = counting_numbers(argc, argv);

    // Выделяем память под массив всех чисел
    array = malloc(sizeof(char *) * (total_numbers + 1));
    if (!array)
        return (ft_printf("Error: args_char_array malloc failed\n"), NULL);

    // Заполняем массив
    array = fill_array(argc, argv, array);
	if (array == NULL)
		return (NULL);
	return (array);
}
