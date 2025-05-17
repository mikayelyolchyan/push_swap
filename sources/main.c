/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:43:46 by miyolchy          #+#    #+#             */
/*   Updated: 2025/05/17 20:17:26 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers/push_swap.h"

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_int_array(int **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

bool	has_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	is_valid_arg(char *argv)
{
	int			index;
	int			i;
	char		**char_array;
	int			count;
	int			*int_array;
	
	char_array = ft_split(argv, ' ');
	index = 0;
	while (char_array[index] != NULL)
	{
		count++;
		index++;
	}
	if (count < 1)
	{
		free_char_array(char_array);
		ft_printf("Invalid count args\n");
		return (false);
	}
	int_array = (int *)malloc(count * sizeof(int));
	if (int_array == NULL)
	{
		ft_printf("Error int arrays malloc\n");
		free_char_array(char_array);
		return (false);
	}
	index = 0;
	while (index < count)
	{
		int_array[index] = ft_atoi(char_array[index]);
		if (int_array[index] == 0)
		{
			i = 0;
			if (char_array[index][i] == '-' || char_array[index][i] == '+')
				i++;
			if (!ft_isdigit(char_array[index][i]))
			{
				ft_printf("%s is invalid argument\n", char_array[index]);
				free_char_array(char_array);
				free(int_array);
				return (false);
			}
			while (char_array[index][i])
			{
				if (!ft_isdigit(char_array[index][i]))
				{
					ft_printf("%s is invalid argument\n", char_array[index]);
					free_char_array(char_array);
					free(int_array);
					return (false);
				}
				i++;
			}
		}
		ft_printf("%d\n", int_array[index]);
		index++;
	}
	if (has_duplicates(int_array, count) == true)
	{
		free_char_array(char_array);
		free(int_array);
		return (false);	
	}
	free_char_array(char_array);
	free(int_array);
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Invalid args count\n");
		return (1);
	}
	if (is_valid_arg(argv[1]) == false)
	{
		ft_printf("Invalid argv\n");
		return (1);
	}
	ft_printf("Valid arguments\n");
	return (0);
}
