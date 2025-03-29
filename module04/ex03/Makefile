# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 14:12:55 by tabadawi          #+#    #+#              #
#    Updated: 2025/01/10 11:28:45 by tabadawi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	interface
CXX			=	c++
CXXFLAGS	=	-std=c++98
CXXFLAGS	+=	-Wall -Wextra -Werror
# CXXFLAGS	+=	-fsanitize=address -g3
SRCS		=	AMateria.cpp Cure.cpp Ice.cpp Character.cpp MateriaSource.cpp main.cpp

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