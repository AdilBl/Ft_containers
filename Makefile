SOURCES_FILES    =	Main.cpp\

HEADER            =    header.hpp

SOURCES            =    $(addprefix ./, $(SOURCES_FILES))

OBJECTS            =     $(SOURCES:.cpp=.o)

NAME            =    Ft_containers

CC                =    c++
RM                =    rm -f

FLAGS            =    -Wall -Wextra -Werror -std=c++98

.cpp.o:$(HEADER)$(MAKEFILE)
		$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

all:            $(NAME)

$(NAME):        $(OBJECTS) $(HEADER)$(MAKEFILE)
		$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

clean:
		$(RM) $(OBJECTS)

fclean:            clean
		$(RM) $(NAME)

re:                fclean all

.PHONY:            all clean fclean re