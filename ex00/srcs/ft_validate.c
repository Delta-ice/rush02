/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinsafw <abinsafw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 17:09:54 by mealmeha          #+#    #+#             */
/*   Updated: 2026/08/02 22:12:59 by abinsafw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	has_hundreds(char *group, t_dictionary *dict)
{
	char	key[2];

	if (group[0] == '0')
		return (1);
	key[0] = group[0];
	key[1] = '\0';
	if (!ft_map_value(key, dict))
		return (0);
	return (ft_map_value("100", dict) != NULL);
}

static int	has_remainder(char *group, t_dictionary *dict)
{
	char	key[3];

	if (group[1] == '1')
	{
		key[0] = '1';
		key[1] = group[2];
		key[2] = '\0';
		return (ft_map_value(key, dict) != NULL);
	}
	if (group[1] != '0')
	{
		key[0] = group[1];
		key[1] = '0';
		key[2] = '\0';
		if (!ft_map_value(key, dict))
			return (0);
	}
	if (group[2] == '0')
		return (1);
	key[0] = group[2];
	key[1] = '\0';
	return (ft_map_value(key, dict) != NULL);
}

static int	has_group(char *group, t_dictionary *dict)
{
	return (has_hundreds(group, dict) && has_remainder(group, dict));
}

int	ft_can_print(char **split, int size, t_dictionary *dict)
{
	char	key[40];
	int		index;
	int		nonzero;

	index = 0;
	nonzero = 0;
	while (index < size)
	{
		if (ft_strcmp(split[index], "000") != 0)
		{
			nonzero = 1;
			if (!has_group(split[index], dict))
				return (0);
			if (size - index - 1 > 0)
			{
				ft_scale_key(key, size - index - 1);
				if (!ft_map_value(key, dict))
					return (0);
			}
		}
		index++;
	}
	return (nonzero || ft_map_value("0", dict) != NULL);
}
