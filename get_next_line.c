/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irene <irene@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:05:45 by iescalon          #+#    #+#             */
/*   Updated: 2024/02/05 14:40:57 by irene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_read(int fd, char *buffer)
{
	char	*line;
	int		readcount;

	readcount = -2;
	line = ft_strdup(buffer);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	line = ft_read(fd, buffer);
}
