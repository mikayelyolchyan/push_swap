/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:56:45 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/15 10:17:48 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

static long long int	char_to_longlongint(const char *nptr)
{
	int				i;
	int				sign;
	long long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == '\f' || nptr[i] == '\n' || nptr[i] == '\r' || \
	nptr[i] == '\t' || nptr[i] == '\v' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

static bool	check_all_str(char **array, int index1, int index2, char char_index)
{
	while (array[index1][index2])
	{
		char_index = array[index1][index2];
		if (ft_isdigit((int)char_index))
			index2++;
		else
			return (false);
	}
	return (true);
}

static bool	all_args_is_numbers(char **array)
{
	long long int	numbers;
	int				index1;
	int				index2;
	char			char_index;

	index1 = 0;
	while (array[index1])
	{
		index2 = 0;
		char_index = array[index1][index2];
		if (char_index == '-' || char_index == '+')
			index2++;
		if (check_all_str(array, index1, index2, char_index) == false)
			return (false);
		numbers = char_to_longlongint(array[index1]);
		if (numbers > INT_MAX || numbers < INT_MIN)
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
