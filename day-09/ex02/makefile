# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 18:24:43 by aaammari          #+#    #+#              #
#    Updated: 2023/08/07 18:25:55 by aaammari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  PmergeMe

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = PmergeMe.hpp

SRCS = main.c PmergeMe.cpp

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
