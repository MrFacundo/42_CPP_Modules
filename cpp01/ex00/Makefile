NAME		= ex00
CC			= c++
CXX			= c++
CXXFLAGS		=-Wall -Wextra -Werror -g -std=c++98
RM			= rm -rf
SRCS		= Zombie.cpp main.cpp randomChump.cpp newZombie.cpp
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

restart		: clean all
			./$(NAME)

re			: fclean $(NAME)

.PHONY		: re fclean clean all
