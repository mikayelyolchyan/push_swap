/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:05:53 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/14 15:14:37 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/instructions.h"

void	rotate_a(t_list **a_list, bool print)
{
	t_list	*a_head;
	t_list	*a_last;

	if (*a_list == NULL || (*a_list)->next == NULL)
		return ;
	a_head = *a_list;
	a_last = ft_lstlast(a_head);
	*a_list = a_head->next;
	a_last->next = a_head;
	a_head->next = NULL;
	if (print == true)
		ft_printf("ra\n");
}
