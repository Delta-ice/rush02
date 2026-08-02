/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernieh <mbernieh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 19:53:56 by mbernieh          #+#    #+#             */
/*   Updated: 2026/08/01 12:05:53 by mbernieh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/rush02.h"

int	loc_split(char **split, int split_size)
{
	int	i;

	i = 0;
	while (i < split_size)
	{
		split[i] = malloc(sizeof(char) * 4);
		if (!split[i])
		{
			while (--i >= 0)
				free(split[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

void	copy_first(int c, char *str, char *split)
{
	int	i;

	i = 0;
	split[0] = '0';
	split[1] = '0';
	split[2] = '0';
	while (i < c)
	{
		split[3 - c + i] = str[i];
		i++;
	}
	split[3] = '\0';
}

void	copy_group(int c, int split_size, char *str, char **split)
{
	int	i;
	int	j;
	int	k;

	k = c;
	i = 1;
	while (str[k] && i < split_size)
	{
		j = 0;
		while (j < 3 && str[k])
		{
			split[i][j] = str[k];
			k++;
			j++;
		}
		split[i][3] = '\0';
		i++;
	}
}

void	get_size(int len, int *split_size, int *c)
{
	if (len % 3 == 0)
	{
		*split_size = len / 3;
		*c = 3;
	}
	else
	{
		*split_size = (len / 3) + 1;
		*c = len % 3;
	}
}

char	**ft_splitstr(char *str, int *split_size)
{
	int		len;
	int		c;
	char	**split;

	if (!str || !split_size)
		return (NULL);
	len = ft_strlen(str);
	if (len == 0)
		return (NULL);
	get_size(len, split_size, &c);
	split = malloc(sizeof(char *) * (*split_size + 1));
	if (!split)
		return (NULL);
	if (!loc_split(split, *split_size))
	{
		free(split);
		return (NULL);
	}
	split[*split_size] = NULL;
	copy_first(c, str, split[0]);
	copy_group(c, *split_size, str, split);
	return (split);
}
