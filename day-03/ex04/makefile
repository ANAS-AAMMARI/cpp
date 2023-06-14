# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 15:16:57 by aaammari          #+#    #+#              #
#    Updated: 2023/06/14 15:01:49 by aaammari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = diamondtrap

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -Wno-shadow

HEADER = FragTrap.hpp ClapTrap.hpp ScavTrap.hpp DiamondTrap.hpp

SRCS = FragTrap.cpp ClapTrap.cpp ScavTrap.cpp main.cpp DiamondTrap.cpp

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
