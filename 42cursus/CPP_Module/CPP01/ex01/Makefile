NAME		= zombie_horde
CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

SRCS		= main.cpp \
			  Zombie.cpp \
			  zombieHorde.cpp

OBJS		= $(SRCS:%.cpp=%.o)

all	:		$(NAME)

$(NAME) : 	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o	: 		%.cpp
			$(CXX) $(CXXFLAGS) -c $^ -I./ -o $@

clean	:
			rm -f $(OBJS)

fclean	:
			make clean
			rm -f $(NAME)

re	:
			make fclean
			make all

.PHONY	:	all clean fclean re