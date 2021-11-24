NAME = libftprintf.a
HEADER = ft_printf.h
CC = gcc
SRCS = ft_printf.c \
		parsing.c \
		type_processing.c \
		type_processing_hex.c \
		tools.c 

OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror -I.$(HEADER)
AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(AR) $(NAME) $(OBJS) $(HEADER)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re