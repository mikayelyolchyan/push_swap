/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:56:45 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/18 22:32:17 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

static bool	all_args_is_numbers(char **array)
{
	int				index1;
	int				index2;
	char			char_index;

	index1 = 0;
	while (array[index1])
	{
		index2 = 0;
		char_index = array[index1][index2];
		if (char_index == '-' || char_index == '+')
		{
			index2++;
			if (!array[index1][index2] || !ft_isdigit(array[index1][index2]))
				return (false);
		}
		if (check_all_str(array, index1, index2, char_index) == false)
			return (false);
		if (is_valid_int(array[index1]) == false)
			return (false);
		index1++;
	}
	return (true);
}

static bool	no_repeating_numbers(char **array)
{
	int		number1;
	int		number2;
	int		index1;
	int		index2;

	index1 = 0;
	while (array[index1])
	{
		number1 = char_to_longlongint(array[index1]);
		index2 = index1 + 1;
		while (array[index2])
		{
			number2 = char_to_longlongint(array[index2]);
			if (number1 == number2)
				return (false);
			index2++;
		}
		index1++;
	}
	return (true);
}

bool	validity_check(char **array)
{
	if (all_args_is_numbers(array) == false)
		return (false);
	if (no_repeating_numbers(array) == false)
		return (false);
	return (true);
}
