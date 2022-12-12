CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = philo

LIB = philo/philo.h

SRCS = 	philo/main.c \
		philo/utils.c \
		philo/philo.c \
		philo/begin_sim.c \
		philo/checkers.c \


OBJS = $(SRCS:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all