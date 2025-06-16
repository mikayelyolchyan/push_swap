/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:44:03 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/16 17:19:26 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/instructions.h"

void	push_a(t_list **a_list, t_list **b_list, bool print)
{
	t_list	*b_head;

	if (*b_list == NULL)
		return ;
	b_head = *b_list;
	*b_list = b_head->next;
	b_head->next = *a_list;
	*a_list = b_head;
	if (print == true)
		ft_dprintf(1, "pa\n");
}
