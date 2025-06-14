/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 12:40:25 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/14 16:42:50 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/push_swap.h"
#include "../../../includes/headers/instructions.h"

void	sort_two(t_list **a)
{
	if (((t_data *)(*a)->content)->number > \
		((t_data *)(*a)->next->content)->number)
		swap_a(a, 1);
}

void	sort_three(t_list **a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = ((t_data *)(*a)->content)->number;
	n2 = ((t_data *)(*a)->next->content)->number;
	n3 = ((t_data *)(*a)->next->next->content)->number;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		swap_a(a, 1);
	else if (n1 > n2 && n2 > n3)
	{
		swap_a(a, 1);
		reverse_rotate_a(a, 1);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		rotate_a(a, 1);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		swap_a(a, 1);
		rotate_a(a, 1);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		reverse_rotate_a(a, 1);
}

void	sort_four(t_list **a, t_list **b)
{
	int	min_pos;

	min_pos = find_min_pos(*a);
	while (min_pos--)
		rotate_a(a, 1);
	push_b(a, b, 1);
	sort_three(a);
	push_a(a, b, 1);
}

void	sort_five(t_list **a, t_list **b)
{
	int	min_pos;

	min_pos = find_min_pos(*a);
	while (min_pos--)
		rotate_a(a, 1);
	push_b(a, b, 1);
	min_pos = find_min_pos(*a);
	while (min_pos--)
		rotate_a(a, 1);
	push_b(a, b, 1);
	sort_three(a);
	push_a(a, b, 1);
	push_a(a, b, 1);
}

void	sort_small_stack(t_list **a, t_list **b, int size)
{
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}
