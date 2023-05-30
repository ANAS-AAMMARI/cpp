# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 12:48:30 by aaammari          #+#    #+#              #
#    Updated: 2023/05/30 12:51:49 by aaammari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter

CFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = HarlFilter.hpp

SRCS = main.cpp			\
		HarlFilter.cpp 	\

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADER)
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
	