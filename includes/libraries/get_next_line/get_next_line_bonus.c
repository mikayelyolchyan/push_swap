/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <miyolchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:58:01 by miyolchy          #+#    #+#             */
/*   Updated: 2025/06/14 15:05:38 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	*clear_remainder(char *remainder)
{
	if (remainder)
		free(remainder);
	return (NULL);
}

static char	*keep_remainder(char *remainder)
{
	char	*new_line;
	char	*tmp;

	new_line = ft_strchr(remainder, '\n');
	if (!new_line)
		return (clear_remainder(remainder));
	tmp = ft_substr(new_line + 1, 0, ft_strlen(new_line + 1));
	clear_remainder(remainder);
	return (tmp);
}

static char	*extract_line(char *remainder)
{
	char	*new_line;

	if (!remainder || !*remainder)
		return (NULL);
	new_line = ft_strchr(remainder, '\n');
	if (!new_line)
		return (ft_substr(remainder, 0, ft_strlen(remainder)));
	return (ft_substr(remainder, 0, new_line - remainder + 1));
}

static char	*read_file(int fd, char *remainder)
{
	char	*tmp;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	read_bytes;

	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(remainder, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buffer[read_bytes] = '\0';
		tmp = remainder;
		remainder = ft_strjoin(tmp, buffer);
		clear_remainder(tmp);
		if (!remainder)
			return (NULL);
	}
	if (read_bytes < 0)
		return (clear_remainder(remainder));
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder[1048576];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1048576)
		return (NULL);
	remainder[fd] = read_file(fd, remainder[fd]);
	if (!remainder[fd])
		return (NULL);
	line = extract_line(remainder[fd]);
	if (!line)
		return (remainder[fd] = clear_remainder(remainder[fd]));
	remainder[fd] = keep_remainder(remainder[fd]);
	return (line);
}
