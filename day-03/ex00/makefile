# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 15:59:35 by aaammari          #+#    #+#              #
#    Updated: 2023/06/11 17:04:37 by aaammari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = ClapTrap.hpp

SRCS = main.cpp ClapTrap.cpp

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