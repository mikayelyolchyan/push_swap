/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 12:23:08 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/14 15:14:03 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/push_swap.h"

int	get_index(t_list *node)
{
	if (!node || !node->content)
		return (-1);
	return (((t_data *)node->content)->index);
}

int	find_max_position(t_list *b)
{
	int			max;
	int			max_pos;
	int			i;
	t_list		*tmp;

	if (!b)
		return (-1);
	tmp = b;
	max = get_index(tmp);
	max_pos = 0;
	i = 0;
	while (tmp)
	{
		if (get_index(tmp) > max)
		{
			max = get_index(tmp);
			max_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max_pos);
}

int	get_chunk_size(int stack_size)
{
	if (stack_size <= 100)
		return (15);
	else if (stack_size <= 500)
		return (30);
	else
		return (stack_size / 10 + 30);
}
