NAME		= main
SRCS		= main.cpp
CXX			= g++

$(NAME):
	$(CXX) -o $(NAME) $(SRCS)

.PHONY: clean
clean:
	$(RM) $(NAME)