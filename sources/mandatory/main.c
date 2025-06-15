/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:43:46 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/15 12:32:24 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

//void	print_list(t_list *list)
//{
//	int	index;

//	index = 0;
//	while (list)
//	{
//		ft_printf("number = %d ", ((t_data *)list->content)->number);
//		ft_printf("index = %d\n", ((t_data *)list->content)->index);
//		list = list->next;
//		index++;
//	}
//	ft_printf("\n");
//}

int	main(int argc, char **argv)
{
	t_list		*a_list;
	t_list		*b_list;
	t_array		array;
	int			size;

	if (argc < 2)
		return (1);
	a_list = creating_list(argc, argv, &array);
	if (a_list == NULL)
		return (ft_printf("Error\n"), 1);
	b_list = NULL;
	if (check_sorted(a_list) == 1 && b_list == NULL)
		return (free_list(a_list), free_list(b_list), 0);
	size = ft_lstsize(a_list);
	if (size >= 2 && size <= 5)
		sort_small_stack(&a_list, &b_list, size);
	else
		butterfly_sort(&a_list, &b_list);
	free_list(a_list);
	free_list(b_list);
	return (0);
}
