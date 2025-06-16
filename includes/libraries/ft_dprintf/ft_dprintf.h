/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:08:55 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/16 17:17:04 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int	ft_dprintf(int fd, const char *format, ...);
int	ft_switch(char spf, va_list args, int fd);
int	print_char(char ch, int fd);
int	print_str(char *str, int fd);
int	print_int(int number, int fd);
int	print_unsigned(unsigned int number, int fd);
int	print_hex_lower(unsigned int number, int fd);
int	print_hex_upper(unsigned int number, int fd);
int	print_ptr(void *ptr, const char *base, int fd);

#endif
