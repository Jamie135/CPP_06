NAME = identify
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
FILES = Base \
		Identifier \
		main

INCLS = Base.hpp \
		A.hpp \
		B.hpp \
		C.hpp \
		Identifier.hpp

SRCS = $(addsuffix .cpp, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $^

.cpp.o: $(SRCS) $(INCLS)
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re