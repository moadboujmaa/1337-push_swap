NAME=push_swap
SRC=push_swap.c ./actions/push.c ./actions/swap.c ./actions/rotate.c ./actions/rrotate.c ./utils/lst.c ./utils/fill_stack.c ./utils/print_error.c ./utils/parse.c ./utils/sort.c ./utils/sort_utils.c ./utils/parse2.c ./utils/sort_utils_2.c
OBJ=$(SRC:.c=.o)
CC=cc
CFLAGS=-Wall -Wextra -Werror -fsanitize=address
LIBFT_AR=./libft/libft.a

all: $(NAME)	

$(LIBFT_AR):
	@make -C ./libft

$(NAME): $(OBJ) $(LIBFT_AR)
	@$(CC) $(SRC) -o $(NAME) $(LIBFT_AR)
	@echo "██████╗ ██╗   ██╗███████╗██╗  ██╗███████╗██╗    ██╗ █████╗ ██████╗ "
	@echo "██╔══██╗██║   ██║██╔════╝██║  ██║██╔════╝██║    ██║██╔══██╗██╔══██╗"
	@echo "██████╔╝██║   ██║███████╗███████║███████╗██║ █╗ ██║███████║██████╔╝"
	@echo "██╔═══╝ ██║   ██║╚════██║██╔══██║╚════██║██║███╗██║██╔══██║██╔═══╝ "
	@echo "██║     ╚██████╔╝███████║██║  ██║███████║╚███╔███╔╝██║  ██║██║     "
	@echo "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     "

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C ./libft
	@rm -f $(OBJ)
	@echo "\033[33mPush_Swap object files removed\033[0m"

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all