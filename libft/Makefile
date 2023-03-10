# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 11:04:16 by jede-ara          #+#    #+#              #
#    Updated: 2023/01/18 18:23:22 by jede-ara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =			ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
					ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
					ft_memmove.c ft_memset.c  ft_strchr.c  ft_strlcat.c ft_strlcpy.c \
					ft_strlen.c  ft_strncmp.c ft_strrchr.c ft_tolower.c ft_toupper.c \
					ft_calloc.c ft_strdup.c ft_strnstr.c ft_substr.c ft_strjoin.c \
					ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
					ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
					
SRC_BONUS =		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
					ft_lstclear.c ft_lstiter.c ft_lstmap.c
			

NAME = libft.a
HDRS = libft.h
CC = cc -c
FLAGS = -Wall -Werror -Wextra
OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(OBJS) $(SRC_BONUS:.c=.o)

# ==================================================================================== 
# COLORS
# ====================================================================================

GREEN		:=	\033[1;32m
RED			:=	\033[1;31m
WHITE		:=	\033[1;37m
BOLD		:=	\033[1;1m

%.o:%.c
	@cc -Wall -Wextra -Werror -o $@ -c $<
	@echo "$(WHITE)[OK] Build completed$(BOLD)"

$(NAME): $(OBJS) $(HDRS)
	@make --no-print-directory -C ./printf
	@$(CC) $(SRC) $(FLAGS)
	@ar r $(NAME) $(OBJS)
	@echo "$(GREEN) [Success] Done the compilation Libft.$(BOLD)"

bonus: $(BONUS_OBJS) $(HDRS)
	@$(CC) $(SRC) $(SRC_BONUS) $(FLAGS)
	@ar r $(NAME) $(BONUS_OBJS)
	@echo "$(GREEN) [Success] Done the compilation Libft with Bonus.$(BOLD)"

all: $(NAME)

clean:
	@make clean -C ./printf 
	@/bin/rm -f $(BONUS_OBJS)
	@/bin/rm -f $(NAME)
	@echo "$(RED) [Deleting] Object files deleted.$(BOLD)"

fclean: clean
	@make fclean -C ./printf
	@/bin/rm -f $(NAME) 
	@echo "$(RED) [Deleting] Libft.a deleted.$(BOLD)"

re: fclean all

.PHONY: all clean fclean re bonus
