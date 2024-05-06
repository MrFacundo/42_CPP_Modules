NAME		= ex02
CXX			= c++
CFLAGS		=-Wall -Wextra -Werror -g -std=c++98
RM			= rm -rf
SRCS		= ClapTrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp
OBJS		= $(SRCS:.cpp=.o)
$(NAME)		: $(OBJS)
			$(CXX) $(CFLAGS) -o $(NAME) $(OBJS)

%.o			: %.c
			$(CXX) $(CFLAGS) -c -o $@ $<

all			: $(NAME)

clean		:
			$(RM) $(OBJS)

fclean		: clean
			$(RM) $(NAME)

restart		: clean all
			./$(NAME)

re			: fclean $(NAME)

.PHONY		: re fclean clean all
