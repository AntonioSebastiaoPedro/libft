# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 11:32:47 by ansebast          #+#    #+#              #
#    Updated: 2024/08/14 18:39:06 by ansebast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
CYAN = \033[0;36m
RESET = \033[0m

SRC = $(filter-out $(BONUS_SRC), $(wildcard ft_*.c))
BONUS_SRC = $(wildcard ft_lst*.c)
OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo -e "$(CYAN)Creating the library $(NAME)...$(RESET)"
	ar rcs $(NAME) $(OBJS)
	@echo -e "$(GREEN)Library $(NAME) successfully created!$(RESET)"

bonus: $(NAME) $(BONUS_OBJS)

$(BONUS_OBJS): %.o: %.c
	@echo -e "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo -e "$(GREEN)Bonus file compiled successfully!$(RESET)"

clean:
	@echo -e "$(RED)Removendo arquivos objeto...$(RESET)"
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@echo -e "$(RED)Removendo a biblioteca $(NAME)...$(RESET)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus