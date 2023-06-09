# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 12:28:28 by aaammari          #+#    #+#              #
#    Updated: 2023/06/05 18:34:15 by aaammari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = Fixed.hpp

SRC = main.cpp 		\
		fixed.cpp	\

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS)  $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
