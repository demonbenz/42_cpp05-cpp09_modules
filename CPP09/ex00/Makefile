
NAME	= btc

CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -I. -std=c++98
SRCS	=	main.cpp BitcoinExchange.cpp

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re

