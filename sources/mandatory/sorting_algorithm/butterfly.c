/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:06:10 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/14 15:14:09 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/instructions.h"
#include "../../../includes/headers/push_swap.h"

void	distribution_of_elements(t_list **a, t_list **b)
{
	int		stack_size;
	int		chunk_size;
	int		i;

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
	}
}

void	return_elements(t_list **a, t_list **b)
{
	int		j;
	int		max_pos;
	int		b_size;

	while (*b)
	{
		max_pos = find_max_position(*b);
		b_size = ft_lstsize(*b);
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
	}
}

void	butterfly_sort(t_list **a, t_list **b)
{
	distribution_of_elements(a, b);
	return_elements(a, b);
}
