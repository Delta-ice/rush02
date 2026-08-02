/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernieh <mbernieh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:55:01 by mbernieh          #+#    #+#             */
/*   Updated: 2026/08/01 18:55:05 by mbernieh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/rush02.h"

void print_unit(char split, t_dict *dict)
{
    char    key[2];
    char    *value;
    
    key[0] = split;
    key[1] = '\0';
    value = ft_map_value(key, dict);
    if (value)
        write(1, value, ft_strlen(value));
}

void	print_tens(char *split, t_dict *dict)
{
	char	key[3];

	if (split[0] == '0')
		return;
	if (split[0] != '1')
	{
		key[0] = split[0];
		key[1] = '0';
		key[2] = '\0';
		print_value(key, dict);
		if (split[1] != '0')
		{
			write(1, " ", 1);
			print_unit(split[1], dict);
		}
	}
	else
	{
		key[0] = '1';
		key[1] = split[1];
		key[2] = '\0';
		print_value(key, dict);
	}
}

void	print_group(char *split, t_dict *dict)
{
	if (split[0] != '0')
	{
		print_unit(split[0], dict);
		write(1, " ", 1);
		print_value("100", dict);
		if (split[1] != '0' || split[2] != '0')
			write(1, " ", 1);
	}
	if (split[1] != '0')
		print_tens(split + 1, dict);
	else if (split[2] != '0')
		print_unit(split[2], dict);
}

void	print_scale(int scale, t_dict *dict)
{
	char	key[40];
	int	i;

	if (scale <= 0)
		return;
	i = 0;
	key[i++] = '1';
	while (i < (scale * 3) + 1)
		key[i++] = '0';
	key[i] = '\0';
	print_value(key, dict);
}

void ft_print_result(char **split,int split_size, t_dict *dict )
{
    int i;
    int scale;

    i = 0;
    scale   = split_size - 1; // scale is the number of groups after current group
    while(i < split_size)
    {
        print_group(split[i], dict);
        if(scale > 0)
        {
            write(1, " ", 1);
            print_scale(scale, dict);
        }
        i++;
        scale--;
    }
}
