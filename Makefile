NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./src_mandatory -I./libft

# Mandatory
SRC_DIR = src_mandatory
SRCS = $(SRC_DIR)/arena.c \
       $(SRC_DIR)/cost_calculation.c \
       $(SRC_DIR)/execute_moves_basic.c \
       $(SRC_DIR)/execute_moves_special.c \
       $(SRC_DIR)/greedy_main.c \
       $(SRC_DIR)/greedy_ranges.c \
       $(SRC_DIR)/libft_tuned.c \
       $(SRC_DIR)/main.c \
       $(SRC_DIR)/parser.c \
       $(SRC_DIR)/push.c \
       $(SRC_DIR)/reverse_rotate.c \
       $(SRC_DIR)/rotate.c \
       $(SRC_DIR)/sort_small.c \
       $(SRC_DIR)/stack_index.c \
       $(SRC_DIR)/stack_operations.c \
       $(SRC_DIR)/strategy_selection.c \
       $(SRC_DIR)/swap.c

OBJS = $(SRCS:.c=.o)

# Bonus
BONUS_DIR = src_bonus
BONUS_SRCS = $(BONUS_DIR)/checker.c \
             $(SRC_DIR)/arena.c \
             $(SRC_DIR)/libft_tuned.c \
             $(SRC_DIR)/parser.c \
             $(SRC_DIR)/push.c \
             $(SRC_DIR)/reverse_rotate.c \
             $(SRC_DIR)/rotate.c \
             $(SRC_DIR)/swap.c \
             $(SRC_DIR)/stack_operations.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
