# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antbarbi <antbarbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 11:02:08 by antbarbi          #+#    #+#              #
#    Updated: 2023/03/20 15:12:28 by antbarbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= btc

INCLUDES		= ./includes
SRCS_FILES		= main.cpp BitcoinExchange.cpp
SRCS			= $(addprefix srcs/, $(SRCS_FILES))
OBJS			= $(SRCS:.cpp=.o)
HEADERS			= $(addprefix includes/, $(HEADERS_FILES))
HEADER_FILES	= BitcoinExchange.hpp


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