/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:57:15 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/06 22:32:51 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/push_swap.h"

void	free_char_array(char **array)
{
	int	index;

	index = 0;
	if (array)
	{
		while (array[index])
		{
			free(array[index]);
			index++;
		}
		free(array);
	}
}

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list->content);
		free(list);
		list = tmp;
	}
}
