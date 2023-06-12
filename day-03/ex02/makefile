# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 15:16:57 by aaammari          #+#    #+#              #
#    Updated: 2023/06/12 15:19:02 by aaammari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FragTrap

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = FragTrap.hpp ClapTrap.hpp ScavTrap.hpp

SRCS = FragTrap.cpp ClapTrap.cpp ScavTrap.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
