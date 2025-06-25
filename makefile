NAME		= main
SRCS		= main.cpp
CXX			= g++

main: $(SRCS)
	$(CXX) -o $(NAME) $(SRCS)

.PHONY: clean
clean:
	$(RM) $(NAME)