CXX			= c++
RM			= rm -f
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC			= main.cpp Utils.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
NAME		= ex02

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
