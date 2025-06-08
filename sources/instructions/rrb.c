/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:46:45 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/08 17:00:09 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/instructions.h"

void	reverse_rotate_b(t_list **b_list, bool print)
{
	t_list	*b_last;
	t_list	*a_second_last;

	if (*b_list == NULL || (*b_list)->next == NULL)
		return ;
	b_last = *b_list;
	a_second_last = NULL;
	while (b_last->next != NULL)
	{
		a_second_last = b_last;
		b_last = b_last->next;
	}
	b_last->next = *b_list;
	a_second_last->next = NULL;
	*b_list = b_last;
	if (print == true)
		ft_printf("rrb\n");
}
