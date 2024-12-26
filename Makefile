NAME_L = libftprintf.a
NAME = push_swap
NAME_BONUS = bonus

CC = cc
C_FLAGS = -Wall -Wextra -Werror

SRCS_L = ft_printf/funcs.c ft_printf/ft_printf.c ft_printf/process_string.c ft_printf/process_string2.c ft_printf/funcs2.c
SRCS = $(wildcard sources/*.c)
SRCS_BONUS = $(wildcard bonus_sources/*.c)
SRCS_GNL = $(wildcard get_next_line/*.c)

OBJS_L = $(SRCS_L:%.c=%.o)
OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)
OBJS_GNL = $(SRCS_GNL:%.c=%.o)

all: $(NAME_L) $(NAME)

$(NAME_L): $(OBJS_L)
	ar rcs $(NAME_L) $(OBJS_L)

$(NAME): $(OBJS) $(NAME_L)
	$(CC) $(C_FLAGS) -o $(NAME) $(OBJS) -L. -lftprintf

%.o: %.c
	$(CC) $(C_FLAGS) -Ift_printf -c $< -o $@

bonus: $(OBJS_BONUS) $(OBJS_GNL)
	$(CC) $(C_FLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(OBJS_GNL)

clean:
	rm -f $(OBJS) $(OBJS_L) $(OBJS_BONUS) $(OBJS_GNL)

fclean: clean
	rm -f $(NAME) $(NAME_L) $(NAME_BONUS)

re: fclean all bonus

.PHONY: all clean fclean re bonus