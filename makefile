CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = philo

LIB = mandatory/philo.h

SRCS = 	mandatory/main.c \
		mandatory/utils.c \
		mandatory/parsing.c \
		mandatory/philo.c \

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