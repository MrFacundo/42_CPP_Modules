NAME		= ex00
CXX			= c++
CFLAGS		=-Wall -Wextra -Werror -g -std=c++98
RM			= rm -rf
SRCS		= Fixed.cpp main.cpp
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

re			: fclean $(NAME)

.PHONY		: re fclean clean all
