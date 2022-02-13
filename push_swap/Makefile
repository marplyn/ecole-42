NAME = push_swap
CHECKER = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -fno-omit-frame-pointer
INCLUDES_PATH = includes/
SRC_PATH = sources/
LIBFT_PATH = Libft/

INCLUDES = $(INCLUDES_PATH)push_swap.h
SRC_FILES = main.c \
			stack_init.c \
			node_operations.c \
			utils.c \
			push.c \
			swap.c \
			rotate.c \
			reverse_rotate.c \
			small_sort.c \
			sorting.c \
			indexes.c \
			radix_sort.c \
			atol.c
SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ = $(SRC:.c=.o)
CHECKER_FILES = checker.c \
				utils.c \
				stack_init.c \
				node_operations.c \
				atol.c \
				push.c \
				swap.c \
				rotate.c \
				reverse_rotate.c
CHECKER_SRC = $(addprefix $(SRC_PATH), $(CHECKER_FILES))
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)
LIBFT = $(LIBFT_PATH)libft.a

all: $(NAME) $(CHECKER)

$(NAME): $(INCLUDES) $(OBJ)
	@echo "\033[95m  \033[1m (ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec \033[0m"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[95m  \033[1m (づ｡◕‿‿◕｡)づ $(NAME) is generated! \033[0m"

%.o: %.c $(INCLUDES) $(LIBFT)
	@$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -c $< -o $@

$(CHECKER): $(INCLUDES) $(CHECKER_OBJ)
	@$(CC) $(CFLAGS) $(CHECKER_OBJ) $(LIBFT) -o $(CHECKER)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@rm -rf  $(OBJ) $(CHECKER_OBJ)
	@$(MAKE) clean -C $(LIBFT_PATH)
	@echo "\033[95m  \033[1m (⊙﹏⊙) Object files are removed! \033[0m"

fclean: clean
	@rm -rf  $(NAME) $(CHECKER)
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@echo "\033[95m  \033[1m (∩︵∩) $(NAME) is removed! \033[0m"

re: fclean all

.PHONY: all clean fclean re