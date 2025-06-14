/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:05:01 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/14 16:07:13 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libraries/libft/libft.h"
# include "../libraries/ft_printf/ft_printf.h"

# include "push_swap.h"

bool	check_sorted(t_list *a_list);
void	do_operation(t_list **a_list, t_list **b_list, char *operation);

#endif