/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:43:49 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/01 19:45:25 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libraries/libft/libft.h"
# include "../libraries/ft_printf/ft_printf.h"

# include <stdbool.h>

typedef struct s_data
{
	int	number;
	int	index;
}	t_data;

void	free_char_array(char **array);

void	free_list(t_list *list);

char	**creating_array(int argc, char **argv, char **args_chars_array);

bool	validity_check(char **array);

#endif
