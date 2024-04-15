NAME		= ex03
CXX			= c++
CXXFLAGS		=-Wall -Wextra -Werror -g -std=c++98
RM			= rm -rf
SRCS		= AForm.cpp main.cpp RobotomyRequestForm.cpp Bureaucrat.cpp  PresidentialPardonForm.cpp  ShrubberyCreationForm.cpp Intern.cpp
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
