/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinsafw <abinsafw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 16:09:47 by mealmeha          #+#    #+#             */
/*   Updated: 2026/08/02 22:34:24 by abinsafw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static void	fill_group(char *group, char *str, int start, int size)
{
	int	index;

	group[0] = '0';
	group[1] = '0';
	group[2] = '0';
	index = 0;
	while (index < size)
	{
		group[3 - size + index] = str[start + index];
		index++;
	}
	group[3] = '\0';
}

static int	allocate_groups(char **split, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		split[index] = malloc(4);
		if (!split[index])
			return (0);
		index++;
	}
	split[index] = NULL;
	return (1);
}

static void	copy_groups(char **split, char *str, int count, int first)
{
	int	index;
	int	start;

	fill_group(split[0], str, 0, first);
	index = 1;
	start = first;
	while (index < count)
	{
		fill_group(split[index], str, start, 3);
		start += 3;
		index++;
	}
}

char	**ft_splitstr(char *str, int *split_size)
{
	char	**split;
	int		first;

	*split_size = (ft_strlen(str) + 2) / 3;
	split = malloc(sizeof(char *) * (*split_size + 1));
	if (!split)
		return (NULL);
	first = ft_strlen(str) % 3;
	if (first == 0)
		first = 3;
	if (!allocate_groups(split, *split_size))
		return (ft_free_split(split), NULL);
	copy_groups(split, str, *split_size, first);
	return (split);
}

void	ft_free_split(char **split)
{
	int	index;

	if (!split)
		return ;
	index = 0;
	while (split[index])
		free(split[index++]);
	free(split);
}
