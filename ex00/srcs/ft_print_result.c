/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinsafw <abinsafw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 03:28:51 by abinsafw          #+#    #+#             */
/*   Updated: 2026/08/02 22:29:47 by abinsafw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	print_key(char *key, t_dictionary *dict, int *printed)
{
	char	*value;

	value = ft_map_value(key, dict);
	if (!value)
		return (0);
	if (*printed)
		ft_putstr(" ");
	ft_putstr(value);
	*printed = 1;
	return (1);
}

static int	print_hundreds(char *group, t_dictionary *dict, int *printed)
{
	char	key[2];

	if (group[0] == '0')
		return (1);
	ft_digit_key(key, group[0]);
	if (!print_key(key, dict, printed))
		return (0);
	return (print_key("100", dict, printed));
}

static int	print_remainder(char *group, t_dictionary *dict, int *printed)
{
	char	key[3];

	if (group[1] == '1')
	{
		key[0] = '1';
		key[1] = group[2];
		key[2] = '\0';
		return (print_key(key, dict, printed));
	}
	if (group[1] != '0')
	{
		key[0] = group[1];
		key[1] = '0';
		key[2] = '\0';
		if (!print_key(key, dict, printed))
			return (0);
	}
	if (group[2] != '0')
	{
		ft_digit_key(key, group[2]);
		return (print_key(key, dict, printed));
	}
	return (1);
}

static int	print_group(char *group, t_dictionary *dict, int *printed)
{
	if (!print_hundreds(group, dict, printed))
		return (0);
	return (print_remainder(group, dict, printed));
}

int	ft_print_result(char **split, int split_size, t_dictionary *dict)
{
	int	index;
	int	printed;

	if (!ft_can_print(split, split_size, dict))
		return (0);
	index = 0;
	printed = 0;
	while (index < split_size)
	{
		if (ft_strcmp(split[index], "000") != 0)
		{
			if (!print_group(split[index], dict, &printed))
				return (0);
			if (!ft_print_scale(split_size - index - 1, dict, &printed))
				return (0);
		}
		index++;
	}
	if (!printed)
		return (print_key("0", dict, &printed));
	return (1);
}
