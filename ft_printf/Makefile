# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 16:29:02 by srouhe            #+#    #+#              #
#    Updated: 2019/11/28 19:24:41 by srouhe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_printf
SRCS = main.c
INCL = ../libft/includes
FLAGS = -Wall -Werror -Wextra
DIR = "${testdir}"
LIBDIR = ../../$(DIR)

all: $(NAME)

$(NAME):
	@make -C $(LIBDIR)
	@gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(INCL) -I $(LIBDIR)/includes -I $(LIBDIR)/libft/includes -L$(LIBDIR) -lftprintf

clean:
	@make clean -C $(LIBDIR)

fclean: clean
	@make fclean -C $(LIBDIR)
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
