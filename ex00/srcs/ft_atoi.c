/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinsafw <abinsafw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 18:47:32 by mealmeha          #+#    #+#             */
/*   Updated: 2026/08/02 20:27:12 by abinsafw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_remove_zeros(char *str)
{
	while (*str == '0' && *(str + 1) != '\0')
		str++;
	return (str);
}

char	*ft_atoi(char *str)
{
	if (!ft_valid_number(str))
		return (0);
	return (ft_remove_zeros(str));
}
