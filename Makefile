NAME=push_swap
SRC=push_swap.c ./instructions/push.c ./instructions/swap.c ./instructions/reverse.c ./utils/lst.c
OBJ=$(SRC:.c=.o)
CC=cc
CFLAGS=-Wall -Wextra -Werror
LIBFT=make -C ./libft

all: $(NAME)	


$(NAME): $(OBJS)
	$(LIBFT)
	$(CC) $(SRC) -o $(NAME) ./libft/libft.a

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C ./libft
	@rm -f $(OBJS) $(BOBJS)
	@echo "\033[33mPush_Swap object files removed\033[0m"

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME) $(BNAME)

re: fclean all