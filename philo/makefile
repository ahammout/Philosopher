CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = philo

LIB = philo.h

SRCS = 	main.c \
		utils.c \
		philo.c \
		begin_sim.c \
		checkers.c \


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