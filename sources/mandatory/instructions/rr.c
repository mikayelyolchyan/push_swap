/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:21:10 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/14 16:41:30 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/instructions.h"

void	rotate_a_and_b(t_list **a_list, t_list **b_list, bool print)
{
	rotate_a(a_list, false);
	rotate_b(b_list, false);
	if (print == true)
		ft_printf("rr\n");
}
