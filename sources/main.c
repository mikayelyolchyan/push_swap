/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:43:46 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/06 22:34:12 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/push_swap.h"

int	main(int argc, char **argv)
{
	int			index;
	t_list		*list;
	t_list		*list_head;
	t_array		array;

	if (argc < 2)
		return (ft_printf("Error: No arguments provided\n"), 1);
	list_head = creating_list(argc, argv, &array);
	if (list_head == NULL)
		return (ft_printf("List creating error\n"), 1);
	list = list_head;
	array.args_count = ft_lstsize(list);
	index = 0;
	while (index < array.args_count)
	{
		ft_printf("number = %d ", ((t_data *)list->content)->number);
		ft_printf("index = %d\n", ((t_data *)list->content)->index);
		list = list->next;
		index++;
	}
	free_list(list_head);
	return (0);
}
