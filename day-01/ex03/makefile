# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 15:13:56 by aaammari          #+#    #+#              #
#    Updated: 2023/05/26 15:25:10 by aaammari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = weapon

CC = c++ 

CFLAGS = -Wall -Werror -Wextra -std=c++98

HEADER = HumanA.hpp HumanB.hpp Weapon.hpp

SRC = 	main.cpp 	\
		HumanA.cpp	\
		HumanB.cpp	\
		Weapon.cpp

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo make is done 

%.o: %.cpp $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@echo everything is cleaned

re: fclean all

.PHONY: all clean fclean re