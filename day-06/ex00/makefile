# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 11:26:28 by aaammari          #+#    #+#              #
#    Updated: 2023/07/09 11:29:37 by aaammari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cast

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = ScalarConversion.hpp

SRCS = main.cpp ScalarConverter.cpp

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
