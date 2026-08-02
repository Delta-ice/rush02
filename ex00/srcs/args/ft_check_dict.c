/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinsafw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 06:07:44 by abinsafw          #+#    #+#             */
/*   Updated: 2026/08/02 06:17:14 by abinsafw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define BUFFERSIZE 4096

int	ft_check_dict(char *dict)
{
	int		fd;
	char	buf[BUFFERSIZE];
	long	bytes;

	fd = open(dict, 0);
	if (fd == -1)
		return (0);
	bytes = read(fd, buf, BUFFERSIZE);
	if (bytes <= 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
