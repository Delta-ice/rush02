# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abinsafw <abinsafw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/02 21:14:14 by abinsafw          #+#    #+#              #
#    Updated: 2026/08/02 22:30:30 by abinsafw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = srcs/main.c srcs/ft_atoi.c srcs/ft_dict.c srcs/ft_file.c \
	srcs/ft_map_value.c srcs/ft_print_result.c srcs/ft_scale.c \
	srcs/ft_splitstr.c srcs/ft_strcmp.c srcs/ft_strlen.c \
	srcs/ft_validate.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
