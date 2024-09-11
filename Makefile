# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 11:32:47 by ansebast          #+#    #+#              #
#    Updated: 2024/09/11 18:21:07 by ansebast         ###   ########.fr        #
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

BONUS_SRC = ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c

SRC = ft_atoi.c \
      ft_bzero.c \
      ft_calloc.c \
      ft_isalnum.c \
      ft_isalpha.c \
      ft_isascii.c \
      ft_isdigit.c \
      ft_isprint.c \
      ft_itoa.c \
      ft_memchr.c \
      ft_memcmp.c \
      ft_memcpy.c \
      ft_memmove.c \
      ft_memset.c \
      ft_putchar_fd.c \
      ft_putendl_fd.c \
      ft_putnbr_fd.c \
      ft_putstr_fd.c \
      ft_split.c \
      ft_strchr.c \
      ft_strdup.c \
      ft_striteri.c \
      ft_strjoin.c \
      ft_strlcat.c \
      ft_strlcpy.c \
      ft_strlen.c \
      ft_strmapi.c \
      ft_strncmp.c \
      ft_strnstr.c \
      ft_strrchr.c \
      ft_strtrim.c \
      ft_substr.c \
      ft_tolower.c \
      ft_toupper.c

BONUS_OBJS = $(BONUS_SRC:.c=.o)

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)Creating the library $(NAME)...$(RESET)"
	ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)Library $(NAME) successfully created!$(RESET)"

bonus: $(OBJS) $(BONUS_OBJS)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.o: .c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)File compiled successfully!$(RESET)"

clean:
	@echo "$(RED)Removing all object files...$(RESET)"
	rm -f $(OBJS) $(BONUS_OBJS) libft.so
	
fclean: clean
	@echo "$(RED)Removing the library $(NAME)...$(RESET)"
	rm -f $(NAME)
	@echo "$(GREEN)Library $(NAME) successfully removed!$(RESET)"

re: fclean all

rebonus: re bonus

.PHONY: all clean fclean re bonus