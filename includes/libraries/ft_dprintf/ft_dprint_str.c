/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprint_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:28:28 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/16 17:23:18 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	print_str(char *str, int fd)
{
	if (str)
	{
		ft_putstr_fd(str, fd);
		return (ft_strlen(str));
	}
	else
	{
		ft_putstr_fd("(null)", fd);
		return (ft_strlen("(null)"));
	}
}
