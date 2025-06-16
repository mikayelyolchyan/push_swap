/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:30:12 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/16 17:18:23 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "../libraries/libft/libft.h"
# include "../libraries/ft_dprintf/ft_dprintf.h"

# include <stdbool.h>

void	swap_a(t_list **a_list, bool print);
void	swap_b(t_list **b_list, bool print);
void	swap_a_and_b(t_list **a_list, t_list **b_list, bool print);
void	push_a(t_list **a_list, t_list **b_list, bool print);
void	push_b(t_list **a_list, t_list **b_list, bool print);
void	rotate_a(t_list **a_list, bool print);
void	rotate_b(t_list **b_list, bool print);
void	rotate_a_and_b(t_list **a_list, t_list **b_list, bool print);
void	reverse_rotate_a(t_list **a_list, bool print);
void	reverse_rotate_b(t_list **b_list, bool print);
void	reverse_rotate_a_and_b(t_list **a_list, t_list **b_list, bool print);

#endif