NAME		=		Bureaucrat
CXX			=		c++
CXXFLAGS	=		-std=c++98
CXXFLAGS	+=		-Wall -Wextra -Werror
SRCS		=		Bureaucrat.cpp AForm.cpp main.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJS		=		$(SRCS:.cpp=.o)

all             :       $(NAME)

%.o             : %.c
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME) :       $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 

clean   :
	@rm -rf $(OBJS)

fclean  :	clean
	@rm -rf $(NAME)

re		:	fclean all