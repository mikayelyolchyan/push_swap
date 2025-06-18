/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 22:31:28 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/18 22:39:57 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/push_swap.h"

long long int	char_to_longlongint(const char *nptr)
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

bool	check_all_str(char **array, int index1, int index2, char char_index)
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

bool	is_valid_int(char *str)
{
	long long int	number;
	size_t			size;
	char			*start;

	start = str;
	if (!*str)
		return (false);
	while (*str == ' ' || *str == '\f' || *str == '\n' || \
		*str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	size = 0;
	if (size > 11)
		return (false);
	if (!*str || !ft_isdigit((int)*str))
		return (false);
	number = char_to_longlongint(start);
	//ft_dprintf(1, "%d\n", number);
	if (number < INT_MIN || number > INT_MAX)
		return (false);
	return (true);
}
