NAME = push_swap

CC = cc

C_FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

SOURCES_DIR = sources
INSTRUCTIONS_DIR = $(SOURCES_DIR)/instructions
HEADER_DIR = includes/headers
LIBRARIES_DIR = includes/libraries

LIBFT_DIR = $(LIBRARIES_DIR)/libft
FT_PRINTF_DIR = $(LIBRARIES_DIR)/ft_printf

SOURCES = $(SOURCES_DIR)/main.c $(SOURCES_DIR)/free.c \
			$(SOURCES_DIR)/creating_array.c $(SOURCES_DIR)/validation.c \
			$(SOURCES_DIR)/bubble_sort.c $(SOURCES_DIR)/creating_list.c \
			$(INSTRUCTIONS_DIR)/sa.c $(INSTRUCTIONS_DIR)/sb.c \
			$(INSTRUCTIONS_DIR)/ss.c $(INSTRUCTIONS_DIR)/pa.c \
			$(INSTRUCTIONS_DIR)/pb.c $(INSTRUCTIONS_DIR)/ra.c \
			$(INSTRUCTIONS_DIR)/rb.c $(INSTRUCTIONS_DIR)/rr.c \
			$(INSTRUCTIONS_DIR)/rra.c $(INSTRUCTIONS_DIR)/rrb.c \
			$(INSTRUCTIONS_DIR)/rrr.c $(SOURCES_DIR)/sorting_algorithm/butterfly.c

OBJECTS = $(SOURCES:%.c=%.o)

HEADER_FLAGS = -I$(HEADER_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
FT_PRINTF_FLAGS = -L$(FT_PRINTF_DIR) -lftprintf

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(C_FLAGS) $(OBJECTS) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all
	@$(MAKE) -C $(LIBFT_DIR) bonus

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR) all

%.o: %.c $(HEADER)
	$(CC) $(C_FLAGS) $(HEADER_FLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	rm -f $(OBJECTS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
