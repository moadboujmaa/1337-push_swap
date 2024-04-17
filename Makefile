NAME=push_swap
BONUS_NAME=checker
SRC=./mandatory/push_swap.c
BSRC=./bonus/checker.c
SHARED=./shared/actions/push.c ./shared/actions/swap.c ./shared/actions/rotate.c ./shared/actions/rrotate.c ./shared/utils/lst.c ./shared/utils/fill_stack.c ./shared/utils/print_error.c ./shared/utils/parse.c ./shared/utils/sort.c ./shared/utils/sort_utils.c ./shared/utils/sort_utils_2.c
OBJ=$(SRC:.c=.o)
BOBJ=$(BSRC:.c=.o)
CC=cc
CFLAGS=-Wall -Wextra -Werror
LIBFT_AR=./shared/libft/libft.a
LIBFT=./shared/libft

all: $(NAME)	

$(LIBFT_AR):
	@make -C $(LIBFT)

$(NAME): $(OBJ) $(LIBFT_AR)
	@$(CC) $(SRC) $(SHARED) -o $(NAME) $(LIBFT_AR)
	@echo "██████╗ ██╗   ██╗███████╗██╗  ██╗███████╗██╗    ██╗ █████╗ ██████╗ "
	@echo "██╔══██╗██║   ██║██╔════╝██║  ██║██╔════╝██║    ██║██╔══██╗██╔══██╗"
	@echo "██████╔╝██║   ██║███████╗███████║███████╗██║ █╗ ██║███████║██████╔╝"
	@echo "██╔═══╝ ██║   ██║╚════██║██╔══██║╚════██║██║███╗██║██╔══██║██╔═══╝ "
	@echo "██║     ╚██████╔╝███████║██║  ██║███████║╚███╔███╔╝██║  ██║██║     "
	@echo "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     "

%.o: %.c ./mandatory/push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BOBJ) $(LIBFT_AR)
	@$(CC) $(BSRC) $(SHARED) -o $(BONUS_NAME) $(LIBFT_AR)

clean:
	@make clean -C $(LIBFT)
	@rm -f $(OBJ)
	@echo "\033[33mPush_Swap object files removed\033[0m"

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all