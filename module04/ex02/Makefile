# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/31 17:42:41 by tabadawi          #+#    #+#              #
#    Updated: 2025/01/10 11:41:09 by tabadawi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Animal
CXX			=	c++
CXXFLAGS	=	-std=c++98
CXXFLAGS	+=	-Wall -Wextra -Werror
# CXXFLAGS	+=	-fsanitize=address -g3
SRCS		=	Animal.cpp Cat.cpp Dog.cpp \
				WrongCat.cpp WrongAnimal.cpp \
				Brain.cpp \
				main.cpp

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