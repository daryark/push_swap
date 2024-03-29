GREEN = \033[0;32m
MAGENTA	= \033[0;35m
YELLOW = \033[0;33m
RESET_COLOR = \033[0m

SRC =	main.c \
		ft_error_check.c list.c idx.c target.c cost.c  math_values.c\
		sort.c sort_big.c choose_rot.c\
		push.c swap.c rot.c rev_rot.c
OBJ = $(addprefix $(OBJ_F), $(SRC:%.c=%.o))

VPATH = $(SRC_F) $(SRC_F)utils/ $(SRC_F)sort/ $(SRC_F)operations/
SRC_F = src/
OBJ_F = obj/

CC = gcc
DEPFLAGS = -MMD -MP
CFLAGS = -Wall -Wextra -Werror -g $(DEPFLAGS)

LIBFT = libft
LIBFLAGS = -L$(LIBFT) -lft

NAME = push_swap



.SILENT:
all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	$(MAKE) -C $(LIBFT);
	$(CC) -o $@ $^ $(LIBFLAGS)
	@echo "$(GREEN)\n———————————✣ PUSH SWAP COMPILED ✣———————————\n$(RESET_COLOR)"

$(OBJ_F)%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@
	@printf "$(GREEN). $(RESET_COLOR)"

clean:
	clear;
	$(MAKE) -C $(LIBFT) fclean;
	rm -rf $(OBJ_F)
	@echo "$(YELLOW)\n☓  CLEAN PUSH SWAP$(RESET_COLOR)"

fclean: clean
	rm -f $(NAME)
	@echo "$(YELLOW)☓☓ FCLEAN PUSH SWAP\n$(RESET_COLOR)"

re: fclean all

.PHONY: all clean fclean re