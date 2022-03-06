NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra

INCLUDES_DIR = includes
SRC_MANDATORY = sources/mandatory/pipex.c \
				sources/mandatory/utils.c
SRC_BONUS = sources/bonus/pipex_bonus.c \
			sources/bonus/utils_bonus.c
SRC_TOOLS = sources/tools/ft_putstr_fd.c \
			sources/tools/ft_split.c \
			sources/tools/ft_strjoin.c \
			sources/tools/ft_strlen.c \
			sources/tools/ft_strncmp.c \
			sources/tools/ft_strnstr.c
SRC_MANDATORY += $(SRC_TOOLS)
SRC_BONUS += $(SRC_TOOLS)
OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

bonus: 
	@make --no-print-directory OBJ_MANDATORY="$(OBJ_BONUS)" all

$(NAME): $(OBJ_MANDATORY)
	@echo "\033[95m  \033[1m (ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec \033[0m"
	@$(CC) $(CFLAGS) $(OBJ_MANDATORY) -o $(NAME)
	@echo "\033[95m  \033[1m (づ｡◕‿‿◕｡)づ $(NAME) is generated! \033[0m"

%.o: %.c $(INCLUDES_DIR)
	@$(CC) $(CFLAGS) -I./$(INCLUDES_DIR) -c $< -o $@

clean:
	@rm -rf  $(OBJ_MANDATORY) $(OBJ_BONUS)
	@echo "\033[95m  \033[1m (⊙﹏⊙) Object files are removed! \033[0m"

fclean: clean
	@rm -rf  $(NAME)
	@echo "\033[95m  \033[1m (∩︵∩) $(NAME) is removed! \033[0m"

re: fclean all

.PHONY: all clean fclean re