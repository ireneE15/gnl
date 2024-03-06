/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iescalon <iescalon@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:22:04 by iescalon          #+#    #+#             */
/*   Updated: 2024/03/06 11:06:39 by iescalon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	char	*filename = "prueba.txt";
	char	*line = NULL;
	int		fd = open(filename, O_RDONLY);
	int		count = 0;
	if (fd == -1)
		return (fd);
	while (1) // Significa que fd existe
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		count++;
		free(line);
	}
	close(fd);
	return (0);
}
