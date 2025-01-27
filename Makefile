SRC = ./Mandatory/get_themax.c ./Mandatory/get_themin.c ./Mandatory/handelsort.c ./Mandatory/parsing.c ./Mandatory/push_swap.c ./Mandatory/push.c \
	  ./Mandatory/reverse_rotate.c ./Mandatory/rotate.c ./Mandatory/swap.c ./Mandatory/utils1.c ./Mandatory/utils2.c ./Mandatory/to_stack.c ./Mandatory/str_int.c ./Mandatory/utils3.c

SRC_BONUS = ./bonus/checker_bonus.c \
            ./bonus/get_next_line_bonus.c \
            ./bonus/get_next_line_utils_bonus.c \
            ./bonus/reverse_rotate_bonus.c \
            ./bonus/rotate_bonus.c \
            ./bonus/swap_bonus.c \
            ./bonus/parsing_bonus.c \
            ./bonus/push_bonus.c \
            ./bonus/utils1_bonus.c \
            ./bonus/utils2_bonus.c \
            ./bonus/to_stack_bonus.c \
            ./bonus/str_int_bonus.c \
			./bonus/get_themax_bonus.c \
			./bonus/get_themin_bonus.c \
            ./bonus/utils3_bonus.c

OBJ_PUSH_SWAP = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror 

NAME = push_swap
BNAME = checker

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ_PUSH_SWAP)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_PUSH_SWAP)

$(BNAME): $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(BNAME) $(OBJ_BONUS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@
bonus: ${BNAME}
clean:
	$(RM) $(OBJ_PUSH_SWAP) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(BNAME)

re: fclean all

.PHONY: all clean fclean re bonus