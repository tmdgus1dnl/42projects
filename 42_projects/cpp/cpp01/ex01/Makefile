NAME = Horde
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Zombie.cpp\
	   main.cpp\
	   zombieHorde.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all dir re clean fclean
