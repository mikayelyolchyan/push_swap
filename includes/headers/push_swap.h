/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:43:49 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/19 18:03:01 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libraries/libft/libft.h"
# include "../libraries/ft_dprintf/ft_dprintf.h"

# include <stdbool.h>

typedef struct s_data
{
	int	number;
	int	index;
}	t_data;

typedef struct s_array
{
	char	**char_args_array;
	int		*int_args_array;
	int		args_count;
}	t_array;

void			free_char_array(char **array);

void			free_list(t_list *list);

char			**creating_char_array(int argc, char **argv, \
				char **args_chars_array);
int				*creating_int_array(int argc, char **argv, t_array *array);

t_list			*creating_list(int argc, char **argv, t_array *array);

bool			validity_check(char **array);

void			bubble_sort(int *array, int args_count);

void			butterfly_sort(t_list **a, t_list **b);

int				get_chunk_size(int stack_size);
int				get_index(t_list *node);
int				find_max_position(t_list *b);

void			sort_small_stack(t_list **a, t_list **b, int size);
int				find_min_pos(t_list *a);

bool			check_sorted(t_list *a_list);

long long int	char_to_longlongint(const char *nptr);

bool			is_valid_int(char *str);
bool			check_all_str(char **array, int index1, \
				int index2, char char_index);

#endif
