/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinsafw <abinsafw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 06:48:46 by abinsafw          #+#    #+#             */
/*   Updated: 2026/08/02 20:44:28 by abinsafw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_file_size(char *filename)
{
	char	buffer[1024];
	int		fd;
	int		read_count;
	int		size;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	size = 0;
	read_count = read(fd, buffer, 1024);
	while (read_count > 0)
	{
		size += read_count;
		read_count = read(fd, buffer, 1024);
	}
	close(fd);
	if (read_count < 0)
		return (-1);
	return (size);
}

char	*ft_read_file(char *filename, int size)
{
	char	*contents;
	int		fd;
	int		at;
	int		read_count;

	contents = malloc(size + 1);
	if (!contents)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(contents), NULL);
	at = 0;
	read_count = read(fd, contents, size);
	while (read_count > 0)
	{
		at += read_count;
		read_count = read(fd, contents + at, size - at);
	}
	close(fd);
	if (read_count < 0 || at != size)
		return (free(contents), NULL);
	contents[size] = '\0';
	return (contents);
}
