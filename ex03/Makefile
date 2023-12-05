# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 11:04:19 by dioda-si          #+#    #+#              #
#    Updated: 2023/12/05 11:04:21 by dioda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			= c++
RM			= rm -f
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC			= main.cpp Utils.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
NAME		= ex03

OBJ			= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)
		$(RM) -f *_shrubbery

re: fclean $(NAME)

r: all
	@./$(NAME)

.PHONY: all clean fclean re r
