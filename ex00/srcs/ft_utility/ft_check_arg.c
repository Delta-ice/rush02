/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinsafw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 06:18:56 by abinsafw          #+#    #+#             */
/*   Updated: 2026/08/02 06:26:34 by abinsafw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utility.h"

int	ft_check_arg(int argc, char **argv, char *default_dict)
{
	if (argc < 2 || argc > 3)
		return (0);
	if (argc == 2)
	{
		if (!ft_valid_number(argv[1]))
			return (0);
		if (!ft_check_dict(default_dict))
		{
			return (-1);
		}
	}
	if (argc == 3)
	{
		if (!ft_check_dict(argv[1]))
		{
			return (-1);
		}
		if (!ft_check_dict(argv[2]))
			return (0);
	}
	return (1);
}
