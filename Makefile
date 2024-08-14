# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 11:32:47 by ansebast          #+#    #+#              #
#    Updated: 2024/08/14 16:38:55 by ansebast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
ARCFLAGS = ar -rcs
CCMD = rm -f
SRC = $(filter-out $(BONUS_SRC), $(wildcard ft_*.c))
OBJS = $(SRC:.c=.o)
BONUS_SRC = $(wildcard ft_lst*.c)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(ARCFLAGS) $(NAME) $(OBJS)

bonus: $(BONUS_OBJS) $(NAME)
	$(ARCFLAGS) $(NAME) $(BONUS_OBJS)
	ranlib $(NAME)

clean:
	$(CCMD) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(CCMD) $(NAME)

re: fclean all

rebonus: re bonus

.PHONY: all clean fclean re bonus
