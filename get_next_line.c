/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iescalon <iescalon@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:05:45 by iescalon          #+#    #+#             */
/*   Updated: 2024/02/16 12:17:59 by iescalon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *str, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		((unsigned char *)str)[count] = 0;
		count++;
	}
}

char	*ft_read(int fd, char *buffer)
{
	char	*line;
	char	*temp;
	int		readcount;

	readcount = -2;
	line = ft_strdup(buffer);
	if (!line)
		return (NULL);
	while (!(ft_strchr(line, '\n')) && readcount != 0)
	{
		readcount = read(fd, buffer, BUFFER_SIZE);
		if (readcount == -1)
		{
			free(line);
			ft_bzero(buffer, BUFFER_SIZE + 1);
			return (NULL);
		}
		buffer[readcount] = '\0';
		temp = ft_strjoin(line, buffer);
		free(line);
		if (!temp)
			return (NULL);
		line = temp;
	}
	return (line);
}

void	ft_new_buffer(char *buffer, char *line, char *nextline)
{
	int	len_nextline;

	if (nextline != NULL)
	{
		len_nextline = nextline - line + 1;
		ft_strlcpy(buffer, nextline + 1, BUFFER_SIZE + 1);
	}
	else
	{
		len_nextline = ft_strlen(line);
		ft_strlcpy(buffer, "", BUFFER_SIZE + 1);
	}
	line[len_nextline] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*nextline;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	line = ft_read(fd, buffer);
	if (!line || *line == '\0')
	{
		free(line);
		return (NULL);
	}
	nextline = ft_strchr(line, '\n');
	if (nextline)
		ft_new_buffer(buffer, line, nextline);
	else
		ft_bzero(buffer, BUFFER_SIZE + 1);
	return (line);
}
