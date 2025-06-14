/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:50:58 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/14 15:15:17 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/headers/instructions.h"

void	reverse_rotate_a_and_b(t_list **a_list, t_list **b_list)
{
	reverse_rotate_a(a_list, false);
	reverse_rotate_b(b_list, false);
	ft_printf("rrr\n");
}
