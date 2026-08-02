/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinsafw <abinsafw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 19:51:54 by abinsafw          #+#    #+#             */
/*   Updated: 2026/08/02 22:13:59 by abinsafw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dict
{
	char	*key;
	char	*value;
}	t_dict;

typedef struct s_dictionary
{
	t_dict	*entries;
	char	*contents;
	int		count;
}	t_dictionary;

typedef t_dictionary	t_dic;

int			ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
int			ft_valid_number(char *str);
char		*ft_atoi(char *str);
int			ft_file_size(char *filename);
char		*ft_read_file(char *filename, int size);
char		**ft_splitstr(char *str, int *split_size);
void		ft_free_split(char **split);
t_dic		*ft_dict(char *filename);
void		ft_free_dict(t_dictionary *dict);
char		*ft_map_value(char *key, t_dictionary *dict);
void		ft_scale_key(char *key, int scale);
void		ft_digit_key(char *key, char digit);
int			ft_print_scale(int scale, t_dictionary *dict, int *printed);
int			ft_can_print(char **split, int size, t_dictionary *dict);
int			ft_print_result(char **split, int split_size, t_dictionary *dict);
void		ft_putstr(char *str);

#endif
