/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:13:54 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/16 17:20:29 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/instructions.h"

void	swap_a(t_list **a_list, bool print)
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
	if (print == true)
		ft_dprintf(1, "sa\n");
}
