# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 15:33:56 by antbarbi          #+#    #+#              #
#    Updated: 2023/03/21 15:34:25 by antbarbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= RPN

INCLUDES		= ./includes
SRCS_FILES		= main.cpp RPN.cpp
SRCS			= $(addprefix srcs/, $(SRCS_FILES))
OBJS			= $(SRCS:.cpp=.o)
HEADERS			= $(addprefix includes/, $(HEADERS_FILES))
HEADER_FILES	= RPN.hpp


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

###############
go: all
	./$(NAME)
###############

############################################
val: all
	@valgrind --leak-check=full ./$(NAME)

############################################


.PHONY:	all clean fclean re