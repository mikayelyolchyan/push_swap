/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:10:41 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/16 17:16:59 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		size;

	size = 0;
	va_start(args, format);
	if (!format || !*format)
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			size = size + ft_switch(*format, args, fd);
		}
		else
		{
			++size;
			ft_putchar_fd(*format, fd);
		}
		++format;
	}
	va_end(args);
	return (size);
}
