/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:17:53 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/14 15:14:40 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/instructions.h"

void	rotate_b(t_list **b_list, bool print)
{
	t_list	*b_head;
	t_list	*b_last;

	if (*b_list == NULL || (*b_list)->next == NULL)
		return ;
	b_head = *b_list;
	b_last = ft_lstlast(b_head);
	*b_list = b_head->next;
	b_last->next = b_head;
	b_head->next = NULL;
	if (print == true)
		ft_printf("rb\n");
}
