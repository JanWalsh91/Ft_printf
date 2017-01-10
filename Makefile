# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 13:07:31 by jwalsh            #+#    #+#              #
#    Updated: 2017/01/10 14:46:56 by jwalsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c \
	  check_flags.c \
	  check_padding.c \
	  check_percent_sign.c \
	  check_precision.c \
	  check_type.c \
	  get_address.c \
	  get_char.c \
	  get_int.c \
	  get_percent.c \
	  get_string.c \
	  get_unsigned_int.c \
	  init_arg.c \
	  parse_arg.c \
	  parse_flags.c \
	  parse_length.c \
	  parse_parameter.c \
	  parse_precision.c \
	  parse_type.c \
	  parse_until_arg.c \
	  parse_width.c \
	  set.c \
	  set_byte_count.c

LIB_SRC = ft_atoi.c \
		  ft_isdigit.c \
		  ft_itoa_base.c \
		  ft_memset.c \
		  ft_strchr.c \
		  ft_strlen.c \
		  ft_strtolower.c \
		  ft_tolower.c \
		  ft_ustrjoinfree.c \
		  ft_ustrncpy.c \
		  ft_ustrnew.c \
		  ft_ustrsjoin.c \
		  ft_wctostr.c

NAME = libftprintf.a

HEAD = ft_printf.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

INC = Libft/

LIB_OBJ = $(LIB_SRC:.c=-.o)
LIB_OBJ = $(addprefix Libft/, *.o)

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
	@make -C Libft/
	@ar rc $(NAME) $(OBJ) $(LIB_OBJ)
	@ranlib $(NAME)
	@$(ECHO) "$(C_CYAN)Libftprintf compilation done.$(C_NONE)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I ./libft.h

clean:
	@rm -f $(OBJ) -I$(INC) $(LIB_OBJ)
	@$(ECHO) "$(C_CYAN)Libftprintf clean done.$(C_NONE)"

fclean: clean
	@make fclean -C ./Libft/
	@rm -f $(NAME) 
	@$(ECHO) "$(C_CYAN)Libftprintf fclean done.$(C_NONE)"

re: fclean
	@$(MAKE) all

.PHONY: clean fclean
	@$(ECHO) "$(C_CYAN)Libftprintf .PHONY done.$(C_NONE)"
