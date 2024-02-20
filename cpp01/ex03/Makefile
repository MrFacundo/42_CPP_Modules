NAME		= ex03
CC			= c++
CXX			= c++
CXXFLAGS		=-Wall -Wextra -Werror -g -std=c++98
RM			= rm -rf
SRCS		= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS		= $(SRCS:.cpp=.o)
$(NAME)		: $(OBJS)
			$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o			: %.c
			$(CC) $(CXXFLAGS) -c -o $@ $<

all			: $(NAME)

clean		:
			$(RM) $(OBJS)

fclean		: clean
			$(RM) $(NAME)

re			: fclean $(NAME)

.PHONY		: re fclean clean all
