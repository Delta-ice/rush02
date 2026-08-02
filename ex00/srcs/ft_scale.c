/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinsafw <abinsafw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:41:22 by abinsafw          #+#    #+#             */
/*   Updated: 2026/08/02 22:11:13 by abinsafw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_scale_key(char *key, int scale)
{
	int	index;

	key[0] = '1';
	index = 1;
	while (index <= scale * 3)
		key[index++] = '0';
	key[index] = '\0';
}

void	ft_digit_key(char *key, char digit)
{
	key[0] = digit;
	key[1] = '\0';
}

int	ft_print_scale(int scale, t_dictionary *dict, int *printed)
{
	char	*value;
	char	key[40];

	if (scale == 0)
		return (1);
	ft_scale_key(key, scale);
	value = ft_map_value(key, dict);
	if (!value)
		return (0);
	if (*printed)
		ft_putstr(" ");
	ft_putstr(value);
	*printed = 1;
	return (1);
}
