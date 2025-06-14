/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:29:30 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/14 16:06:35 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/checker.h"
#include "../../includes/libraries/get_next_line/get_next_line.h"

int	main(int argc, char **argv)
{
	t_list		*a_list;
	t_list		*b_list;
	t_array		array;
	char		*operation;

	if (argc < 2)
		return (ft_printf("Error: No arguments provided\n"), 1);
	a_list = creating_list(argc, argv, &array);
	if (a_list == NULL)
		return (ft_printf("List creating error\n"), 1);
	b_list = NULL;
	operation = get_next_line(0);
	while (operation != NULL)
	{
		do_operation(&a_list, &b_list, operation);
		operation = get_next_line(0);
	}
	if (check_sorted(a_list) == 1 && b_list == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_list(a_list);
	free_list(b_list);
	return (0);
}
