/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:43:46 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/08 20:29:52 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/push_swap.h"
#include "../includes/headers/instructions.h"

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

void print_stack(t_list *list)
{
	t_list *list_copy;

	list_copy = list;
	while (list_copy)
	{
		ft_printf("%d -> ", ((t_data *)list_copy->content)->number);
		list_copy = list_copy->next;
	}
	ft_printf("NULL\n");
}

int	main(int argc, char **argv)
{
	t_list		*a_list;
	t_list		*b_list;
	t_array		array;

	if (argc < 2)
		return (ft_printf("Error: No arguments provided\n"), 1);
	a_list = creating_list(argc, argv, &array);
	if (a_list == NULL)
		return (ft_printf("List creating error\n"), 1);
	b_list = NULL;

	//ft_printf("before \n");
	//ft_printf("a  ");
	//print_stack(a_list);
	//ft_printf("b  ");
	//print_stack(b_list);
	//print_list(a_list);
	//print_list(b_list);

	// test instructions
	butterfly_sort(&a_list, &b_list);

	//ft_printf("\nafter\n");
	////print_list(a_list);
	////print_list(b_list);
	//ft_printf("a  ");
	//print_stack(a_list);
	//ft_printf("b  ");
	//print_stack(b_list);
	

	free_list(a_list);
	free_list(b_list);
	return (0);
}
