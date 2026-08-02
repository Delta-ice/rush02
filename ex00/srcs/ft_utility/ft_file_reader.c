/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinsafw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 06:48:46 by abinsafw          #+#    #+#             */
/*   Updated: 2026/08/02 07:10:43 by abinsafw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_utility.h"

#define BUFFERSIZE 4096

long	file_size(char *file)
{
	long	bytes;
	char	buffer[BUFFERSIZE];
	int		fd;

	fd = open(file, 0);
	bytes = read(fd, buffer, BUFFERSIZE);
	close (fd);
	return (bytes);
}

char	*ft_file_reader(char *file)
{
	int	fd;
	char	*buffer;
	long	bytes;

	bytes = file_size(file);
	if (bytes == -1)
	{
		ft_error("Error\n");
		return (NULL);
	}
	fd = open(file, 0);
	buffer = (char *)malloc(bytes);
	bytes = read(fd, buffer, bytes);
	if (bytes == -1)
	{
		ft_error("Error\n");
		close(fd);
		return (NULL);
	}
	close(fd);
	return (buffer);
}
