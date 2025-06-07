/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:13:54 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/07 16:46:02 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

void	swap_a(t_list **a_list)
{
	t_list	*first;
	t_list	*second;

	if (!a_list || !*a_list || !(*a_list)->next)
		return ;
	first = *a_list;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a_list = second;
	ft_putstr_fd("sa\n", 1);
}