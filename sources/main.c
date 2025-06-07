/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:43:46 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/07 16:48:02 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/push_swap.h"

void print_list(t_list *list)
{
	int	index;

	index = 0;
	while (list)
	{
		ft_printf("number = %d ", ((t_data *)list->content)->number);
		ft_printf("index = %d\n", ((t_data *)list->content)->index);
		list = list->next;
		index++;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_list		*a_list_head;
	t_array		array;

	if (argc < 2)
		return (ft_printf("Error: No arguments provided\n"), 1);
	a_list_head = creating_list(argc, argv, &array);
	if (a_list_head == NULL)
		return (ft_printf("List creating error\n"), 1);

	ft_printf("before swap a\n");
	print_list(a_list_head);

	// test instructions
	swap_a(&a_list_head);

	ft_printf("after swap a\n");
	print_list(a_list_head);

	free_list(a_list_head);
	return (0);
}
