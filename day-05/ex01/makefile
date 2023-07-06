# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 15:50:54 by aaammari          #+#    #+#              #
#    Updated: 2023/07/06 10:43:55 by aaammari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Form

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = Bureaucrat.hpp Form.hpp

SRCS = main.cpp Bureaucrat.cpp Form.cpp

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
