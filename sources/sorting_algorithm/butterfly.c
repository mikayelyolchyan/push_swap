/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:06:10 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/08 20:26:22 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/instructions.h"
#include "../../includes/headers/push_swap.h"

int get_index(t_list *node)
{
    if (!node || !node->content)
        return -1;
    return ((t_data *)node->content)->index;
}

// Находит позицию максимального элемента в стеке B
int	find_max_position(t_list *b)
{
	int		max;
	int		max_pos;
	int		i;
	t_list	*tmp;
    
	if (!b)
    	return -1;
	tmp = b;
	max = get_index(tmp);
	max_pos = 0;
	i = 0;

	while (tmp)
	{
		if (get_index(tmp) > max)
		{
			max = get_index(tmp);
			max_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max_pos);
}

static int	get_chunk_size(int stack_size)
{
	if (stack_size <= 100)
		return 15;
	else if (stack_size <= 500)
		return 30;
	else
		return stack_size / 10 + 30;
}

void	distribution_of_elements(t_list **a, t_list **b)
{
	int stack_size;
	int chunk_size;
	int	i;

	stack_size = ft_lstsize(*a);
	chunk_size = get_chunk_size(stack_size);
	i = 0;
	while (*a)
	{
		if (get_index(*a) <= i)
		{
			push_b(a, b);
			i++;
        }
		else if (get_index(*a) <= i + chunk_size)
		{
			push_b(a, b);
			rotate_b(b, 1);
			i++;
		}
		else
			rotate_a(a, 1);
		
		//ft_printf("a  ");
		//print_stack(*a);
		//ft_printf("b  ");
		//print_stack(*b);
	}
}

void	return_elements(t_list **a, t_list **b)
{
	int	j;
	int max_pos;
	int b_size;

	while (*b)
	{
		max_pos = find_max_position(*b);
		b_size = ft_lstsize(*b);
		// Выбираем оптимальное направление вращения
		if (max_pos <= b_size / 2)
		{
			j = 0;
			while (j++ < max_pos)
				rotate_b(b, 1);
		}
		else
		{
			j = b_size - max_pos;
			while (j-- > 0)
				reverse_rotate_b(b, 1);
		}
		push_a(a, b);

		//ft_printf("a  ");
		//print_stack(*a);
		//ft_printf("b  ");
		//print_stack(*b);
	}
}

void butterfly_sort(t_list **a, t_list **b)
{
	distribution_of_elements(a, b);
	return_elements(a, b);
}
