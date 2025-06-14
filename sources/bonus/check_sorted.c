/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:03:40 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/14 16:07:40 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/checker.h"

bool	check_sorted(t_list *a_list)
{
	while (a_list && a_list->next)
	{
		if (((t_data *)a_list->content)->number > \
			((t_data *)a_list->next->content)->number)
			return (0);
		a_list = a_list->next;
	}
	return (1);
}
