/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernieh <mbernieh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 12:47:42 by mbernieh          #+#    #+#             */
/*   Updated: 2026/08/01 14:19:59 by mbernieh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/rush02.h"

void	parse_line(char *line, t_dict *dict, int index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	dict[index].key = malloc(sizeof(char) * 100);
	dict[index].value = malloc(sizeof(char) * 100);
	if (!dict[index].key || !dict[index].value)
		return ;
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		dict[index].key[j++] = line[i++];
	dict[index].key[j] = '\0';
	while (line[i] == ':' || line[i] == ' ')
		i++;
	j = 0;
	while (line[i])
		dict[index].value[j++] = line[i++];
	dict[index].value[j] = '\0';
}

int	read_line(int fd, char *line)
{
	int		i;
	char	c;

	i = 0;
	while (read(fd, &c, 1) > 0 && c != '\n')
	{
		if (i < 99)
			line[i++] = c;
	}
	line[i] = '\0';
	if (i == 0 && c != '\n')
		return (0);
	return (1);
}

t_dict	*ft_dict(char *filename)
{
	int		fd;
	int		index;
	char	line[100];
	t_dict	*dict;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	dict = malloc(sizeof(t_dict) * 41);
	if (!dict)
	{
		close(fd);
		return (NULL);
	}
	index = 0;
	while (read_line(fd, line))
		parse_line(line, dict, index++);
	close(fd);
	return (dict);
}
