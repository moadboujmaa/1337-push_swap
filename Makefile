NAME=push_swap
SRC=push_swap.c ./actions/push.c ./actions/swap.c ./actions/rotate.c ./actions/rrotate.c ./utils/lst.c ./utils/fill_stack.c
OBJ=$(SRC:.c=.o)
CC=cc
CFLAGS=-Wall -Wextra -Werror
LIBFT=make -C ./libft

all: $(NAME)	


$(NAME): $(OBJ)
	@$(LIBFT)
	@$(CC) $(SRC) -o $(NAME) ./libft/libft.a
	@echo "\033[32;1mPush_Swap Ready to execute\033[0m"

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