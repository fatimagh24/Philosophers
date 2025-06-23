CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
SRC = main.c helpers.c initialize.c ft_free.c philo_routine.c simulation.c libft_utils.c
OBJ = ${SRC:.c=.o}
NAME = philo

all:$(NAME)


$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)


clean :
		rm -f $(OBJ)
fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY: all, re, clean, fclean
