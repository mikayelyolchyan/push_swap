/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:02:31 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/16 17:02:23 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/instructions.h"

bool	do_operation(t_list **a_list, t_list **b_list, char *operation)
{
	if (ft_strncmp(operation, "sa\n", 3) == 0)
		swap_a(a_list, 0);
	else if (ft_strncmp(operation, "sb\n", 3) == 0)
		swap_b(b_list, 0);
	else if (ft_strncmp(operation, "ss\n", 3) == 0)
		swap_a_and_b(a_list, b_list, 0);
	else if (ft_strncmp(operation, "pa\n", 3) == 0)
		push_a(a_list, b_list, 0);
	else if (ft_strncmp(operation, "pb\n", 3) == 0)
		push_b(a_list, b_list, 0);
	else if (ft_strncmp(operation, "ra\n", 3) == 0)
		rotate_a(a_list, 0);
	else if (ft_strncmp(operation, "rb\n", 3) == 0)
		rotate_b(b_list, 0);
	else if (ft_strncmp(operation, "rr\n", 3) == 0)
		rotate_a_and_b(a_list, b_list, 0);
	else if (ft_strncmp(operation, "rra\n", 4) == 0)
		reverse_rotate_a(a_list, 0);
	else if (ft_strncmp(operation, "rrb\n", 4) == 0)
		reverse_rotate_b(b_list, 0);
	else if (ft_strncmp(operation, "rrr\n", 4) == 0)
		reverse_rotate_a_and_b(a_list, b_list, 0);
	else
		return (ft_printf("Error\n"), false);
	return (free(operation), true);
}
