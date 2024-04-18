NAME=push_swap
BONUS_NAME=checker

SRC=./mandatory/push_swap.c ./mandatory/actions/push.c ./mandatory/actions/swap.c ./mandatory/actions/rotate.c ./mandatory/actions/rrotate.c ./mandatory/utils/lst.c ./mandatory/utils/fill_stack.c ./mandatory/utils/print_error.c ./mandatory/utils/parse.c ./mandatory/utils/sort.c ./mandatory/utils/sort_utils.c ./mandatory/utils/sort_utils_2.c
BONUS_SRC=./bonus/checker.c ./bonus/actions/push.c ./bonus/actions/swap.c ./bonus/actions/rotate.c ./bonus/actions/rrotate.c ./bonus/utils/lst.c ./bonus/utils/fill_stack.c ./bonus/utils/print_error.c ./bonus/utils/parse.c ./bonus/utils/sort.c ./bonus/utils/sort_utils.c ./bonus/utils/sort_utils_2.c

OBJ=$(SRC:.c=.o)
BONUS_OBJ=$(BONUS_SRC:.c=.o)

CC=cc
CFLAGS=-Wall -Wextra -Werror
LIBFT_AR=./mandatory/libft/libft.a
LIBFT=./mandatory/libft
LIBFT_AR_BONUS=./bonus/libft/libft.a
LIBFT_BONUS=./bonus/libft

all: $(NAME)	

$(LIBFT_AR):
	@make -C $(LIBFT)

$(LIBFT_AR_BONUS):
	@make -C $(LIBFT_BONUS)

$(NAME): $(OBJ) $(LIBFT_AR)
	@$(CC) $(SRC) -o $(NAME) $(LIBFT_AR)
	@echo "██████╗ ██╗   ██╗███████╗██╗  ██╗███████╗██╗    ██╗ █████╗ ██████╗ "
	@echo "██╔══██╗██║   ██║██╔════╝██║  ██║██╔════╝██║    ██║██╔══██╗██╔══██╗"
	@echo "██████╔╝██║   ██║███████╗███████║███████╗██║ █╗ ██║███████║██████╔╝"
	@echo "██╔═══╝ ██║   ██║╚════██║██╔══██║╚════██║██║███╗██║██╔══██║██╔═══╝ "
	@echo "██║     ╚██████╔╝███████║██║  ██║███████║╚███╔███╔╝██║  ██║██║     "
	@echo "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     "

bonus: $(BONUS_OBJ) $(LIBFT_AR_BONUS)
	@$(CC) $(BONUS_SRC) -o $(BONUS_NAME) $(LIBFT_AR_BONUS)
	@echo "██████╗ ██╗   ██╗███████╗██╗  ██╗███████╗██╗    ██╗ █████╗ ██████╗ "
	@echo "██╔══██╗██║   ██║██╔════╝██║  ██║██╔════╝██║    ██║██╔══██╗██╔══██╗"
	@echo "██████╔╝██║   ██║███████╗███████║███████╗██║ █╗ ██║███████║██████╔╝"
	@echo "██╔═══╝ ██║   ██║╚════██║██╔══██║╚════██║██║███╗██║██╔══██║██╔═══╝   _   _            __ "
	@echo "██║     ╚██████╔╝███████║██║  ██║███████║╚███╔███╔╝██║  ██║██║      |_) / \ |\ | | | (_  "
	@echo "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝      |_) \_/ | \| |_| __) "

%.o: %.c ./mandatory/push_swap.h ./bonus/push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT)
	@make clean -C $(LIBFT_BONUS)
	@rm -f $(OBJ) $(BONUS_OBJ)
	@echo "\033[33mPush_Swap object files removed\033[0m"

fclean: clean
	@make fclean -C $(LIBFT)
	@make fclean -C $(LIBFT_BONUS)
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all