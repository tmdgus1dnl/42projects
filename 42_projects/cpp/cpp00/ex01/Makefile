NAME = PhoneBook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Contact.cpp\
	   PhoneBook.cpp\
	   chk.cpp\
	   get.cpp\
	   print.cpp\
	   retry.cpp\
	   trim.cpp\
	   main.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all dir re clean fclean
