# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 11:37:27 by antbarbi          #+#    #+#              #
#    Updated: 2023/03/24 11:39:01 by antbarbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= PmergeMe

INCLUDES		= ./includes
SRCS_FILES		= main.cpp PmergeMe.cpp
SRCS			= $(addprefix srcs/, $(SRCS_FILES))
OBJS			= $(SRCS:.cpp=.o)
HEADERS			= $(addprefix includes/, $(HEADERS_FILES))
HEADER_FILES	= PmergeMe.hpp


CXX				= c++

CXXFLAGS		= -Wall -Wextra -Werror -std=c++98 -I$(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(HEADERS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

############################################
val: all
	@valgrind --leak-check=full ./$(NAME)

############################################


.PHONY:	all clean fclean re