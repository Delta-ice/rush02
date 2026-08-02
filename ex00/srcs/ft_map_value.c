/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinsafw <abinsafw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:54:48 by mbernieh          #+#    #+#             */
/*   Updated: 2026/08/02 20:45:27 by abinsafw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_map_value(char *key, t_dictionary *dict)
{
	int	i;

	i = 0;
	while (i < dict->count)
	{
		if (ft_strcmp(dict->entries[i].key, key) == 0)
			return (dict->entries[i].value);
		i++;
	}
	return (NULL);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
