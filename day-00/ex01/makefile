# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 14:06:44 by aaammari          #+#    #+#              #
#    Updated: 2023/05/24 10:57:38 by aaammari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = PhoneBook

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

HEADER = Contact.hpp PhoneBook.hpp

SRC = Contact.cpp		\
		main.cpp		\
		PhoneBook.cpp	\

OBJ = $(SRC:%.cpp=%.o)

all: $(Name)

$(Name): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(Name)

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(Name)

re: fclean all

.PHONY: all clean fclean re
