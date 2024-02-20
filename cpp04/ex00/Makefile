NAME		= ex00
CXX			= c++
CXXFLAGS		=-Wall -Wextra -Werror -g -std=c++98
RM			= rm -rf
SRCS		= Animal.cpp Cat.cpp Dog.cpp WrongCat.cpp WrongAnimal.cpp main.cpp
OBJS		= $(SRCS:.cpp=.o)
$(NAME)		: $(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o			: %.c
			$(CXX) $(CXXFLAGS) -c -o $@ $<

all			: $(NAME)

clean		:
			$(RM) $(OBJS)

fclean		: clean
			$(RM) $(NAME)

re			: fclean $(NAME)

.PHONY		: re fclean clean all
