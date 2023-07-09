# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 15:50:54 by aaammari          #+#    #+#              #
#    Updated: 2023/07/08 11:39:47 by aaammari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Intern

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = AForm.hpp Bureaucrat.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp

SRCS = main.cpp 				  	\
		AForm.cpp 				  	\
		Bureaucrat.cpp 			  	\
		ShrubberyCreationForm.cpp 	\
		RobotomyRequestForm.cpp   	\
		PresidentialPardonForm.cpp	\
		Intern.cpp

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
