CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = main.c helpers.c
OBJ = ${SRC:.c=.o}
NAME = philo
LIBFT_DIR = libft
LIBFT_A = libft/libft.a

all:$(LIBFT_A) $(NAME)

$(LIBFT_A) :
		make -C $(LIBFT_DIR)

$(NAME) : $(OBJ)
		@$(CC) $(FLAGS) -o $@ $^ -L $(LIBFT_DIR) -o $@


clean :
		$(MAKE) clean -C $(LIBFT_DIR)
		rm -f $(OBJ)
fclean : clean
		$(MAKE) fclean -C $(LIBFT_DIR)
		rm -f $(NAME)

re : fclean all

.PHONY: all, re, clean, fclean
