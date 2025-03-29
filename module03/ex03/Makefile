# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 13:00:25 by tabadawi          #+#    #+#              #
#    Updated: 2024/12/25 11:46:04 by tabadawi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	DiamondTrap
CXX			=	c++
CXXFLAGS	=	-std=c++98
CXXFLAGS	+=	-Wall -Wextra -Werror
SRCS		=	ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp main.cpp
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