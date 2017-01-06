# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 13:07:31 by jwalsh            #+#    #+#              #
#    Updated: 2016/12/29 12:14:54 by jwalsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 

NAME = libftprintf.a

HEAD = libftprintf.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

ECHO = echo

C_NONE = \033[0m
C_BOLD = \033[1m
C_BLACK = \033[30m
C_RED = \033[31m
C_GREEN = \033[32m
C_BROWN = \033[33m
C_BLUE = \033[34m
C_MAGENTA = \033[35m
C_CYAN = \033[36m
C_GRAY = \033[37m

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@$(ECHO) "$(C_CYAN)Libftprintf compilation done.$(C_NONE)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I ./$(HEAD)

clean:
	@rm -f $(OBJ)
	@$(ECHO) "$(C_CYAN)Libftprintf clean done.$(C_NONE)"

fclean: clean
	@rm -f $(NAME)
	@$(ECHO) "$(C_CYAN)Libftprintf fclean done.$(C_NONE)"

re: fclean
	@$(MAKE) all

.PHONY: clean fclean
	@$(ECHO) "$(C_CYAN)Libftprintf .PHONY done.$(C_NONE)"
