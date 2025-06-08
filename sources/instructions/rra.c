/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:40:22 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/08 16:59:55 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/instructions.h"

void	reverse_rotate_a(t_list **a_list, bool print)
{
	t_list	*a_last;
	t_list	*a_second_last;

	if (*a_list == NULL || (*a_list)->next == NULL)
		return ;
	a_last = *a_list;
	a_second_last = NULL;
	while (a_last->next != NULL)
	{
		a_second_last = a_last;
		a_last = a_last->next;
	}
	a_last->next = *a_list;
	a_second_last->next = NULL;
	*a_list = a_last;
	if (print == true)
		ft_printf("rra\n");
}
