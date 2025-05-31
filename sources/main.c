/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:43:46 by miyolchy          #+#    #+#             */
/*   Updated: 2025/05/31 19:06:54 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/push_swap.h"

int main(int argc, char **argv)
{
    char	**args_chars_array;
    int		index;

    if (argc < 2)
	{
        return (ft_printf("Error: No arguments provided\n"), 1);
	}

	args_chars_array = NULL;
	args_chars_array = creating_array(argc, argv, args_chars_array);

    // Выводим результат
    index = 0;
    while (args_chars_array[index])
    {
        ft_printf("%s\n", args_chars_array[index]);
        index++;
    }
	ft_printf("%s\n", args_chars_array[index]);
	
    free_array(args_chars_array);
    return (0);
}
