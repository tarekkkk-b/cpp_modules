# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 18:35:30 by tabadawi          #+#    #+#              #
#    Updated: 2024/12/21 20:54:51 by tabadawi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	FragTrap
CXX			=	c++
CXXFLAGS	=	-std=c++98
CXXFLAGS	+=	-Wall -Wextra -Werror
SRCS		=	ClapTrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp
OBJS		=	$(SRCS:.cpp=.o)

all		:	$(NAME)

%.o		: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 

clean	:
	@rm -rf $(OBJS)

fclean	:	clean
	@rm -rf $(NAME)

re		: fclean all

.PHONY	: all clean fclean re