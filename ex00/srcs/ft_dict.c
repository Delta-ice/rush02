/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinsafw <abinsafw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 12:47:42 by mbernieh          #+#    #+#             */
/*   Updated: 2026/08/02 22:36:11 by abinsafw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	parse_entry(char *line, t_dict *entry)
{
	char	*key;
	char	*end;

	while (*line == ' ' || *line == '\t')
		line++;
	key = line;
	while (*line >= '0' && *line <= '9')
		line++;
	if (line == key)
		return (0);
	end = line;
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line != ':')
		return (0);
	*end = '\0';
	line++;
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == '\0')
		return (0);
	entry->key = key;
	entry->value = line;
	return (1);
}

static int	parse_dict(char *contents, t_dict *entries)
{
	char	*line;
	char	*next;
	int		count;

	line = contents;
	count = 0;
	while (*line)
	{
		next = line;
		while (*next && *next != '\n')
			next++;
		if (*next)
			*next++ = '\0';
		if (!parse_entry(line, entries + count))
			return (-1);
		count++;
		line = next;
	}
	return (count);
}

t_dictionary	*ft_dict(char *filename)
{
	t_dictionary	*dict;
	int				size;

	size = ft_file_size(filename);
	if (size <= 0)
		return (NULL);
	dict = malloc(sizeof(t_dictionary));
	if (!dict)
		return (NULL);
	dict->contents = ft_read_file(filename, size);
	dict->entries = malloc(sizeof(t_dict) * (size + 1));
	if (!dict->contents || !dict->entries)
		return (ft_free_dict(dict), NULL);
	dict->count = parse_dict(dict->contents, dict->entries);
	if (dict->count <= 0)
		return (ft_free_dict(dict), NULL);
	return (dict);
}

void	ft_free_dict(t_dictionary *dict)
{
	if (!dict)
		return ;
	free(dict->entries);
	free(dict->contents);
	free(dict);
}
