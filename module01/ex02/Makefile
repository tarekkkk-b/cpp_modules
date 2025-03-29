# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tabadawi <tabadawi@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/29 21:35:32 by tabadawi          #+#    #+#              #
#    Updated: 2024/09/28 17:10:42 by tabadawi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	brain
CXX			=	c++
CXXFLAGS	=	-std=c++98
CXXFLAGS	+=	-Wall -Wextra -Werror
SRCS		=	main.cpp
OBJS		=	$(SRCS:.cpp=.o)

all		:	$(NAME)

%.o		: %.c
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) 

clean	:
	@rm -rf $(OBJS)

fclean	:	clean
	@rm -rf $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
