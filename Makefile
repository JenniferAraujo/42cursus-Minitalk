# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jede-ara <jede-ara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 12:16:33 by jede-ara          #+#    #+#              #
#    Updated: 2023/01/19 16:37:41 by jede-ara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minitalk.a
HDRS = ft_minitalk.h
CC = cc 
FLAGS = -Wall -Werror -Wextra
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
LIBFT = ./libft/libft.a
PRINTF = ./libft/printf/libftprintf.a

# ==================================================================================== 
# COLORS
# ====================================================================================

GREEN		:=	\033[1;32m
RED			:=	\033[1;31m
WHITE		:=	\033[1;37m
BOLD		:=	\033[1;1m

all: $(CLIENT) $(SERVER)

$(CLIENT):
	@make --no-print-directory -C ./libft
	$(CC) $(FLAGS) client.c $(LIBFT) $(PRINTF) -o client
	@echo "$(GREEN) [Success] client created.$(BOLD)"

$(SERVER):
	@make --no-print-directory -C ./libft
	$(CC) $(FLAGS) server.c $(LIBFT) $(PRINTF) -o server
	@echo "$(GREEN) [Success] server created.$(BOLD)"

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS):
	@make --no-print-directory -C ./libft
	$(CC) $(FLAGS) ft_strjoincharacter.c client_bonus.c $(LIBFT) $(PRINTF) -o client_bonus
	@echo "$(GREEN) [Success] client_bonus created.$(BOLD)"

$(SERVER_BONUS):
	@make --no-print-directory -C ./libft
	$(CC) $(FLAGS) ft_strjoincharacter.c server_bonus.c $(LIBFT) $(PRINTF) -o server_bonus
	@echo "$(GREEN) [Success] server_bonus created.$(BOLD)"

clean:
	@make clean -C ./libft
	rm -rf client server server_bonus client_bonus
	@echo "$(RED) [Deleting] object files deleted.$(BOLD)"

fclean: clean
	@make fclean -C ./libft 
	@echo "$(RED) [Deleting] .a deleted.$(BOLD)"

re: fclean all

.PHONY: all clean fclean re
