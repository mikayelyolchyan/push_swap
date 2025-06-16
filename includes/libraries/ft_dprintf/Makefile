NAME = libftdprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I../libft

AR = ar -rcs

SRCS = ft_dprintf.c ft_dswitch.c ft_dprint_char.c ft_dprint_str.c ft_dprint_int.c ft_dprint_unsigned.c \
		ft_dprint_hex_lower.c ft_dprint_hex_upper.c ft_dprint_ptr.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

LIBFT = ../libft/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ../libft all
	$(MAKE) -C ../libft bonus

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_dprintf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C ../libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ../libft fclean

re: fclean all

.PHONY: all clean fclean re
