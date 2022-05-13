NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc

HEADER = so_long.h
SRC_MANDATORY = src/mandatory/image.c \
				src/mandatory/moves.c \
				src/mandatory/so_long.c
SRC_BONUS = src/bonus/enemy_bonus.c \
			src/bonus/image_bonus.c \
			src/bonus/moves_bonus.c \
			src/bonus/so_long_bonus.c
SRC = src/actions.c \
		src/display_error.c \
		src/map_check.c \
		src/map_init.c
SRC_TOOLS = src/utils/ft_putstr_fd.c \
			src/utils/ft_strlcpy.c \
			src/utils/ft_strlen.c \
			src/utils/ft_putnbr_fd.c \
			src/utils/ft_itoa.c
SRC_GNL = get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c
HEADER_GNL = get_next_line/get_next_line.h

SRC_MANDATORY += $(SRC)
SRC_MANDATORY += $(SRC_TOOLS)
SRC_MANDATORY += $(SRC_GNL)
OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)

SRC_BONUS += $(SRC)
SRC_BONUS += $(SRC_TOOLS)
SRC_BONUS += $(SRC_GNL)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I$(HEADER) -I$(HEADER_GNL)
MLX = -L mlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ_MANDATORY) $(HEADER) $(HEADER_GNL)
	@echo "\033[95m  \033[1m (ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec \033[0m"
	@make -s -C ./mlx
	@$(CC) $(CFLAGS) $(MLX) $(OBJ_MANDATORY) -o $(NAME)
	@echo "\033[95m  \033[1m (づ｡◕‿‿◕｡)づ $(NAME) is generated! \033[0m"

$(NAME_BONUS): $(OBJ_BONUS) $(HEADER) $(HEADER_GNL)
	@echo "\033[95m  \033[1m (ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec \033[0m"
	@make -s -C ./mlx
	@$(CC) $(CFLAGS) $(MLX) $(OBJ_BONUS) -o $(NAME_BONUS)
	@echo "\033[95m  \033[1m (づ｡◕‿‿◕｡)づ $(NAME_BONUS) is generated! \033[0m"

bonus: $(NAME_BONUS)

%.o: %.c $(HEADER) $(HEADER_GNL)
	@$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@

clean:
	@make clean -s -C ./mlx
	@rm -rf  $(OBJ_MANDATORY) $(OBJ_BONUS)
	@echo "\033[95m  \033[1m (⊙﹏⊙) Object files are removed! \033[0m"

fclean: clean
	@make clean -s -C ./mlx
	@rm -rf  $(NAME) $(NAME_BONUS)
	@echo "\033[95m  \033[1m (∩︵∩) $(NAME) is removed! \033[0m"

re: fclean all
	@make re -s -C ./mlx

.PHONY: all clean fclean re