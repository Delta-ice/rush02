/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinsafw <abinsafw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 20:10:04 by abinsafw          #+#    #+#             */
/*   Updated: 2026/08/02 22:33:32 by abinsafw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static void	put_error(char *message)
{
	write(1, message, ft_strlen(message));
}

int	main(int argc, char **argv)
{
	t_dictionary	*dict;
	char			**split;
	char			*number;
	int				split_size;

	if (argc == 2)
		dict = ft_dict("dict/numbers.dict");
	else if (argc == 3)
		dict = ft_dict(argv[1]);
	else
		return (put_error("Error\n"), 1);
	number = ft_atoi(argv[argc - 1]);
	if (!number)
		return (ft_free_dict(dict), put_error("Error\n"), 1);
	if (!dict)
		return (put_error("Dict Error\n"), 1);
	split = ft_splitstr(number, &split_size);
	if (!split || split_size > 13 || !ft_print_result(split, split_size, dict))
		put_error("Dict Error\n");
	else
		put_error("\n");
	ft_free_split(split);
	ft_free_dict(dict);
	return (0);
}
