/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:54:18 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/14 15:14:34 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/instructions.h"

void	push_b(t_list **a_list, t_list **b_list)
{
	t_list	*a_head;

	if (*a_list == NULL)
		return ;
	a_head = *a_list;
	*a_list = a_head->next;
	a_head->next = *b_list;
	*b_list = a_head;
	ft_printf("pb\n");
}
