/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:24:44 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/14 15:13:52 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

static t_list	*list_elements_alloc(t_array *array, t_list *list)
{
	int		index;
	t_data	*node_data;

	index = 0;
	while (index < array->args_count)
	{
		node_data = malloc(sizeof(t_data));
		if (!node_data)
			return (ft_printf("t_data allocation error\n"), NULL);
		node_data->number = array->int_args_array[index];
		node_data->index = -1;
		ft_lstadd_back(&list, ft_lstnew(node_data));
		index++;
	}
	return (list);
}

static void	fill_list(t_array *array, t_list *list)
{
	int	index;

	while (list)
	{
		index = 0;
		while (index < array->args_count)
		{
			if (((t_data *)list->content)->number == \
				array->int_args_array[index])
			{
				((t_data *)list->content)->index = index;
				break ;
			}
			index++;
		}
		list = list->next;
	}
}

t_list	*creating_list(int argc, char **argv, t_array *array)
{
	t_list	*list;
	t_list	*list_head;

	array->int_args_array = creating_int_array(argc, argv, array);
	if (array->int_args_array == NULL)
		return (NULL);
	list = NULL;
	list = list_elements_alloc(array, list);
	bubble_sort(array->int_args_array, array->args_count);
	list_head = list;
	fill_list(array, list);
	free(array->int_args_array);
	return (list_head);
}
