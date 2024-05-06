NAME		= ex02
CXX			= c++
CXXFLAGS	=-Wall -Wextra -Werror -g -std=c++98
RM			= rm -rf
SRCS		= Base.cpp A.cpp B.cpp C.cpp main.cpp
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

restart		: clean all
			./$(NAME)

re			: fclean $(NAME)

.PHONY		: re fclean clean all
