# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dground <dground@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 17:20:45 by sserwyn           #+#    #+#              #
#    Updated: 2022/07/26 23:29:07 by dground          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
NAME	= libft.a
HEADER	= libft.h
SRC		= ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putnbr_fd.c

B_SRC	= ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

ADD_SRC	= ft_atof.c \
			ft_swap_float.c

SRC		+= $(ADD_SRC)

B_OBJ	= $(B_SRC:.c=.o)

OBJ		= $(SRC:.c=.o)
CFLAGS	= -Wall -Werror -Wextra -I.$(HEADER)
RM		= rm -f
AR  	= ar -rcs

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			$(AR) $(NAME) $(OBJ) $(HEADER)

%.o:		%.c $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJ) $(B_OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:		$(OBJ) $(B_OBJ) $(HEADER)
			$(AR) $(NAME) $(B_OBJ) $(OBJ) $(HEADER)

# so:
# 			gcc -shared -o libft.so *.o

.PHONY:		all clean fclean re bonus
