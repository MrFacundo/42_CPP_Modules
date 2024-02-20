NAME		= ex02
CC			= c++
CXX			= c++
CFLAGS		=-Wall -Wextra -Werror -g -std=c++98
RM			= rm -rf
SRCS		= main.cpp Account.cpp
OBJS		= $(SRCS:.cpp=.o)
$(NAME)		: $(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o			: %.c
			$(CC) $(CFLAGS) -c -o $@ $<

all			: $(NAME)

clean		:
			$(RM) $(OBJS)

fclean		: clean
			$(RM) $(NAME)

re			: fclean $(NAME)

.PHONY		: re fclean clean all
