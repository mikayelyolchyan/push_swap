/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:38:18 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/08 17:02:17 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers/instructions.h"

void	swap_a_and_b(t_list **a_list, t_list **b_list)
{
	swap_a(a_list, false);
	swap_b(b_list, false);
	ft_putstr_fd("ss\n", 1);
}
