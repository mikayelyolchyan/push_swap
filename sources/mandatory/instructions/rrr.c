/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:50:58 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/16 17:20:07 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/instructions.h"

void	reverse_rotate_a_and_b(t_list **a_list, t_list **b_list, bool print)
{
	reverse_rotate_a(a_list, false);
	reverse_rotate_b(b_list, false);
	if (print == true)
		ft_dprintf(1, "rrr\n");
}
