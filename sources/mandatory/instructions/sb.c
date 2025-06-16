/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:34:22 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/16 17:20:40 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/instructions.h"

void	swap_b(t_list **b_list, bool print)
{
	t_list	*first;
	t_list	*second;

	if (!b_list || !*b_list || !(*b_list)->next)
		return ;
	first = *b_list;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b_list = second;
	if (print == true)
		ft_dprintf(1, "sb\n");
}
