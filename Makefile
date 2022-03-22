# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 11:41:26 by tnicoue           #+#    #+#              #
#    Updated: 2022/03/03 11:00:18 by tnicoue          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME		= push_swap

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC			= ft_accept_utils.c ft_accept_utils2.c ft_accept.c ft_atoi.c \
			ft_lstadd_back.c ft_lstclear.c ft_lstnew.c ft_parse.c ft_parse2.c \
			ft_print_lst.c ft_sort_2_3.c ft_sort_4.c ft_sort_5.c ft_sort_big.c \
			ft_sort_big_utils.c ft_sortchoose.c ft_split.c ft_strcmp.c \
			ft_strdup.c ft_strlen.c ft_substr.c ft_utils.c ft_utils2.c \
			ft_utils3.c push_swap.c ft_lstadd_front.c
OBJ			= ${SRC:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): ${OBJ}
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
