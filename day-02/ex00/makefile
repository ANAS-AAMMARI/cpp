# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 12:28:28 by aaammari          #+#    #+#              #
#    Updated: 2023/06/05 17:11:16 by aaammari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = Fixed.hpp

SRC = main.cpp 		\
		fixed.cpp	\

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS)  $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
