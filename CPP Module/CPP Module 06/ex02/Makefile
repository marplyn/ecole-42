CC			= c++
NAME		= identify
SRCS		= main.cpp \
				Base.cpp
HEADERS		=  A.hpp \
				B.hpp \
				C.hpp \
				Base.hpp

CC_FLAGS	= -Wall -Wextra -Werror -std=c++98 -O3
RM			= rm -f

OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
	$(CC) $(SRCS) $(CC_FLAGS) -o $(NAME)

%.o:		%.cpp $(HEADERS)
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re: clean all