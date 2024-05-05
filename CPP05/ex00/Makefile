
NAME	=	Bureaucrat

CC	=	g++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS	=	Bureaucrat.cpp
MAIN	=	main.cpp

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS) $(MAIN) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re

