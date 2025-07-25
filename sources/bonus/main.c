/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:29:30 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/16 17:37:52 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/checker.h"
#include "../../includes/libraries/get_next_line/get_next_line.h"

int	main(int argc, char **argv)
{
	t_list		*a_list;
	t_list		*b_list;
	t_array		array;
	char		*operation;

	if (argc < 2)
		return (0);
	a_list = creating_list(argc, argv, &array);
	if (a_list == NULL)
		return (ft_dprintf(2, "Error\n"), 1);
	b_list = NULL;
	operation = get_next_line(0);
	while (operation != NULL)
	{
		if (do_operation(&a_list, &b_list, operation) == false)
			return (free_list(a_list), free_list(b_list), 1);
		operation = get_next_line(0);
	}
	if (check_sorted(a_list) == 1 && b_list == NULL)
		ft_dprintf(1, "OK\n");
	else
		ft_dprintf(1, "KO\n");
	free_list(a_list);
	free_list(b_list);
	return (0);
}
