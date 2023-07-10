# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 10:58:03 by aaammari          #+#    #+#              #
#    Updated: 2023/07/10 10:59:37 by aaammari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serializer

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = Serializer.hpp

SRCS = main.cpp Serializer.cpp

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
