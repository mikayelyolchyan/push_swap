/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 12:50:57 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/14 12:51:47 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

int	find_min_pos(t_list *a)
{
	int	min;
	int	pos;
	int	i;
	int	min_pos;

	min = ((t_data *)a->content)->number;
	pos = 0;
	i = 0;
	min_pos = 0;
	while (a)
	{
		if (((t_data *)a->content)->number < min)
		{
			min = ((t_data *)a->content)->number;
			min_pos = i;
		}
		a = a->next;
		i++;
	}
	return (min_pos);
}
