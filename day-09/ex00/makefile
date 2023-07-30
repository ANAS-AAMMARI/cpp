# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 15:18:39 by aaammari          #+#    #+#              #
#    Updated: 2023/07/29 15:57:37 by aaammari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = BitcoinExchange.hpp

SRCS = main.cpp BitcoinExchange.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
