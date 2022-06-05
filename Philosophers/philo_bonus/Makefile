NAME = philo_bonus
HEADER = philo_bonus.h
SRC = destroy_bonus.c \
		ft_philo_bonus.c \
		init_bonus.c \
		main_bonus.c \
		monitor_bonus.c \
		utils_bonus.c
CC = gcc
FLAGS = -Wall -Wextra -Werror -pthread

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	@echo "\033[95m  \033[1m (ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Wait a sec \033[0m"
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@echo "\033[95m  \033[1m (づ｡◕‿‿◕｡)づ $(NAME) is generated! \033[0m"

all: $(NAME) $(OBJS) $(HEADER)

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@echo "\033[95m  \033[1m (⊙﹏⊙) Object files are removed! \033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[95m  \033[1m (∩︵∩) $(NAME) is removed! \033[0m"

re: fclean all

.PHONY: all clean fclean re