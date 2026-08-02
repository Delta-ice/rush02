/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernieh <mbernieh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:54:48 by mbernieh          #+#    #+#             */
/*   Updated: 2026/08/01 18:54:54 by mbernieh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/rush02.h"

char	*ft_map_value(char *key, t_dict *dict)
{
	int	i;

	i = 0;
	while (dict[i].key)
	{
		if (ft_strcmp(dict[i].key, key) == 0)
			return (dict[i].value);
		i++;
	}
	return (NULL);
}
void	print_value(char *key, t_dict *dict)
{
	char	*value;

	value = ft_map_value(key, dict);
	if (value)
		write(1, value, ft_strlen(value));
}
