NAME = test_gnl
DIR = "${testdir}"
SRCS = $(DIR)/get_next_line.c main.c
INCL = $(DIR)/
FLAGS = -Wall -Werror -Wextra
LIBDIR = $(DIR)/libft

all: $(NAME)

$(NAME):
	@make -C $(LIBDIR)
	@gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(INCL) -I $(LIBDIR)/includes -L$(LIBDIR) -lft

clean:
	@make clean -C $(LIBDIR)

fclean: clean
	@make fclean -C $(LIBDIR)
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all
.PHONY: clean
.PHONY: fclean
.PHONY: re
