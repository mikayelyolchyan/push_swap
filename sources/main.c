/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:43:46 by miyolchy          #+#    #+#             */
/*   Updated: 2025/05/17 21:55:42 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/push_swap.h"

void free_array(char **array)
{
    int index = 0;
    if (array)
    {
        while (array[index])
        {
            free(array[index]);
            index++;
        }
        free(array);
    }
}

int main(int argc, char **argv)
{
    char **args_chars_array;
    char **args_chars_tmp_array;
    int total_numbers = 0;
    int index1, index2, i, j;

    if (argc < 2)
        return (ft_printf("Error: No arguments provided\n"), 1);

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

    // Выделяем память под массив всех чисел
    args_chars_array = malloc(sizeof(char *) * (total_numbers + 1));
    if (!args_chars_array)
        return (ft_printf("Error: args_chars_array malloc failed\n"), 1);

    // Заполняем массив
    index1 = 0;
    i = 1;
    while (i < argc)
    {
        args_chars_tmp_array = ft_split(argv[i], ' ');
        if (!args_chars_tmp_array)
        {
            free_array(args_chars_array);
            return (ft_printf("Error: ft_split failed\n"), 1);
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

    // Выводим результат
    index1 = 0;
    while (args_chars_array[index1])
    {
        ft_printf("%s\n", args_chars_array[index1]);
        index1++;
    }

    free_array(args_chars_array);
    return (0);
}
