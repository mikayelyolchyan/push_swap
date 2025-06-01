/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:43:46 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/01 20:29:54 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/push_swap.h"

void	args_swap(int *a, int *b)
{
	int	tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(int *array, int args_count)
{
	int	i;
	int	j;

	i = 0;
	while (i < args_count - 1)
	{
		j = 0;
		while (j < args_count - i - 1)
		{
			if (array[j] > array[j + 1])
				args_swap(&array[j], &array[j + 1]);
			j++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
    char	**args_chars_array;
	int		*args_int_array;
    int		index;
	int		args_count;
	t_list	*list;
	t_list	*list_head;
	t_data	*node_data;

    if (argc < 2)
	{
        return (ft_printf("Error: No arguments provided\n"), 1);
	}

	args_chars_array = NULL;
	args_chars_array = creating_array(argc, argv, args_chars_array);

	if (validity_check(args_chars_array) == false)
	{
		free_char_array(args_chars_array);
		return (1);
	}

	index = 0;
	args_count = 0;
	while (args_chars_array[index] != NULL)
	{
		args_count++;
		index++;
	}
	ft_printf("args count = %d\n", args_count);

	args_int_array = (int *)malloc(args_count * sizeof(int));
	if (!args_int_array)
	{
		free_char_array(args_chars_array);
		return (1);
	}
	index = 0;
	while (index < args_count)
	{
		args_int_array[index] = ft_atoi(args_chars_array[index]);
		index++;
	}

	index = 0;
	list = NULL;
	while (index < args_count)
	{
		node_data = malloc(sizeof(t_data));
		if (!node_data)
			return (ft_printf("t_data allocation error\n"), 1);
		node_data->number = args_int_array[index];
		node_data->index = -1;
		ft_lstadd_back(&list, ft_lstnew(node_data));
		index++;
	}

	bubble_sort(args_int_array, args_count);

	list_head = list;
	while (list)
	{
		index = 0;
		while (index < args_count)
		{		
			if (((t_data *)list->content)->number == args_int_array[index])
			{
				((t_data *)list->content)->index = index;
				break ;
			}
			index++;
		}
		list = list->next;
	}

	index = 0;
	list = list_head;
    while (index < args_count)
    {
        ft_printf("number = %d ", ((t_data *)list->content)->number);
		ft_printf("index = %d\n", ((t_data *)list->content)->index);
		list = list->next;
        index++;
    }
	
	free_list(list_head);
    free_char_array(args_chars_array);
	free(args_int_array);
    return (0);
}
