/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinsafw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 03:57:55 by abinsafw          #+#    #+#             */
/*   Updated: 2026/08/02 04:58:15 by abinsafw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	check_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	word_counter(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while(check_charset(str[i], charset))
			i++;
		if (str[i])
		{
			count++;
			while (!check_charset(str[i], charset) && str[i])
				i++;
		}
	}
	return (count);
}

static int	word_counter_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !check_charset(str[i], charset))
		i++;
	return (i);
}

static char	*add_word(char *str, int len)
{
	char	*word;
	int	i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int	i;
	int	j;
	int	word_len;

	result = (char **)malloc(sizeof(char *) * (word_counter(str, charset) + 1));
	if (!result)
		return (0);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (check_charset(str[i], charset))
			i++;
		word_len = word_counter_len(str + i, charset);
		if (word_len)
		{
			result[j] = add_word(str + i, word_len);
			j++;
		}
		i += word_len;
		word_len = 0;
	}
	result[j] = 0;
	return (result);
}
