/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iescalon <iescalon@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:05:45 by iescalon          #+#    #+#             */
/*   Updated: 2024/03/06 10:57:33 by iescalon         ###   ########.fr       */
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
	char	*temp; // Almacena temporalmente la concatenación de line y buffer
	int		readcount; // Contador de cantidad de carácteres leídos por iteración

	readcount = -2;
	line = ft_strdup(buffer);
	if (!line)
		return (NULL);
	while (!(ft_strchr(line, '\n')) && readcount != 0) // Si es 0, es el final del archivo
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
		len_nextline = ft_strlen(line); // Line es última línea
		ft_strlcpy(buffer, "", BUFFER_SIZE + 1); // Se llena con cadena vacía, sin residuos de la línea anterior
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
