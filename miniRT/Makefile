CC				= clang

CFLAGS			= -Wall -Werror -Wextra -I$(DIR_HEADERS) -MMD -O3
# CFLAGS			+= -O1 -g -fsanitize=address -fno-omit-frame-pointer

NAME			= miniRT

DIR_HEADERS		= includes/

RM				= rm -rf

SRCS_DIR		= srcs/
SRCS			= $(addprefix $(SRCS_DIR), main.c)
PARSING_DIR		= parsing/
RENDER_DIR		= render/
TOOLS_DIR		= tools/
SRCS_PARSING	= $(shell find srcs/parsing -name '*.c') # TODO: fix
SRCS_RENDER		= $(shell find srcs/render -name '*.c') # TODO: fix
SRCS_TOOLS		= $(shell find srcs/tools -name '*.c') # TODO: fix
SRCS			+= $(SRCS_PARSING) $(SRCS_RENDER) $(SRCS_TOOLS)

OBJS_DIR		= objs/
OBJS			= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

LIBFT_DIR		= libft/
LIBFT_FLAGS		= -Llibft -lft
LIBFT			= libft/libft.a

MLX_DIR			= mlx_linux/
MLX_FLAGS_LINUX	= -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz
MLX_FLAGS_MAC	= -L$(MLX_DIR) -lmlx_Darwin -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz
LIBMLX			= $(addprefix $(MLX_DIR), libmlx_Linux)

GNL_DIR			= get_next_line/
GNL_FILES		= get_next_line.c \
					get_next_line_utils.c

SRCS			+= $(addprefix $(GNL_DIR), $(GNL_FILES))

OS				= $(shell uname -s)

ifeq ($(OS), Darwin)
	MLX_FLAGS = $(MLX_FLAGS_MAC)
endif
ifeq ($(OS), Linux)
	MLX_FLAGS = $(MLX_FLAGS_LINUX)
endif


.PHONY:		all clean fclean re norm

all:			$(OBJS_DIR) $(LIBMLX) $(LIBFT) $(NAME)

$(OBJS_DIR):
				mkdir -p $(addprefix $(OBJS_DIR), $(GNL_DIR))
				mkdir -p $(addprefix $(addprefix $(OBJS_DIR), $(SRCS_DIR)), $(PARSING_DIR))
				mkdir -p $(addprefix $(addprefix $(OBJS_DIR), $(SRCS_DIR)), $(RENDER_DIR))
				mkdir -p $(addprefix $(addprefix $(OBJS_DIR), $(SRCS_DIR)), $(TOOLS_DIR))

$(LIBFT):
				make bonus --directory $(LIBFT_DIR)

$(LIBMLX):
				chmod +x $(addprefix $(MLX_DIR), configure)
				make all --directory $(MLX_DIR)

$(NAME):		$(OBJS) $(DIR_HEADERS) $(GNL_DIR) $(LIBFT_DIR)
				$(CC) $(OBJS) $(CFLAGS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

$(OBJS_DIR)%.o:	%.c $(DIR_HEADERS) $(GNL_DIR) $(LIBFT_DIR)
				$(CC) $(CFLAGS) -I/usr/include -I$(MLX_DIR) -c $< -o $@

clean:
				$(RM) $(OBJS_DIR)
				make clean --directory $(LIBFT_DIR)
				make clean --directory $(MLX_DIR)

fclean:			clean
				$(RM) $(NAME)
				make fclean --directory $(LIBFT_DIR)
				make clean --directory $(MLX_DIR)

re:				fclean all

norm:
				find . -name "*.c" -or -name "*.h" | grep --invert-match $(MLX_DIR) | xargs norminette
