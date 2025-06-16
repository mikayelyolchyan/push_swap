NAME1 = push_swap
NAME2 = checker

CC = cc
C_FLAGS = -Wall -Wextra -Werror # -g3 -fsanitize=address

MANDATORY_SOURCES_DIR = sources/mandatory
BONUS_SOURCES_DIR = sources/bonus
INSTRUCTIONS_DIR = $(MANDATORY_SOURCES_DIR)/instructions
HEADER_DIR = includes/headers
LIBRARIES_DIR = includes/libraries

LIBFT_DIR = $(LIBRARIES_DIR)/libft
FT_PRINTF_DIR = $(LIBRARIES_DIR)/ft_dprintf
GET_NEXT_LINE_DIR = $(LIBRARIES_DIR)/get_next_line

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftdprintf.a

LIBFT_FLAGS = -L$(LIBFT_DIR) -lft
FT_PRINTF_FLAGS = -L$(FT_PRINTF_DIR) -lftdprintf

HEADER_FLAGS = -I$(HEADER_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)
BONUS_HEADER_FLAGS = -I$(HEADER_DIR) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I$(GET_NEXT_LINE_DIR)

MANDATORY_SOURCES = \
	$(MANDATORY_SOURCES_DIR)/main.c \
	$(MANDATORY_SOURCES_DIR)/free.c \
	$(MANDATORY_SOURCES_DIR)/creating_array.c \
	$(MANDATORY_SOURCES_DIR)/validation.c \
	$(MANDATORY_SOURCES_DIR)/bubble_sort.c \
	$(MANDATORY_SOURCES_DIR)/creating_list.c \
	$(MANDATORY_SOURCES_DIR)/check_sorted.c \
	$(INSTRUCTIONS_DIR)/sa.c \
	$(INSTRUCTIONS_DIR)/sb.c \
	$(INSTRUCTIONS_DIR)/ss.c \
	$(INSTRUCTIONS_DIR)/pa.c \
	$(INSTRUCTIONS_DIR)/pb.c \
	$(INSTRUCTIONS_DIR)/ra.c \
	$(INSTRUCTIONS_DIR)/rb.c \
	$(INSTRUCTIONS_DIR)/rr.c \
	$(INSTRUCTIONS_DIR)/rra.c \
	$(INSTRUCTIONS_DIR)/rrb.c \
	$(INSTRUCTIONS_DIR)/rrr.c \
	$(MANDATORY_SOURCES_DIR)/sorting_algorithm/butterfly.c \
	$(MANDATORY_SOURCES_DIR)/sorting_algorithm/butterfly_utils.c \
	$(MANDATORY_SOURCES_DIR)/sorting_algorithm/small_sort.c \
	$(MANDATORY_SOURCES_DIR)/sorting_algorithm/small_sort_utils.c

MANDATORY_SOURCES_NO_MAIN = \
	$(MANDATORY_SOURCES_DIR)/free.c \
	$(MANDATORY_SOURCES_DIR)/creating_array.c \
	$(MANDATORY_SOURCES_DIR)/validation.c \
	$(MANDATORY_SOURCES_DIR)/bubble_sort.c \
	$(MANDATORY_SOURCES_DIR)/creating_list.c \
	$(INSTRUCTIONS_DIR)/sa.c \
	$(INSTRUCTIONS_DIR)/sb.c \
	$(INSTRUCTIONS_DIR)/ss.c \
	$(INSTRUCTIONS_DIR)/pa.c \
	$(INSTRUCTIONS_DIR)/pb.c \
	$(INSTRUCTIONS_DIR)/ra.c \
	$(INSTRUCTIONS_DIR)/rb.c \
	$(INSTRUCTIONS_DIR)/rr.c \
	$(INSTRUCTIONS_DIR)/rra.c \
	$(INSTRUCTIONS_DIR)/rrb.c \
	$(INSTRUCTIONS_DIR)/rrr.c 

BONUS_SOURCES = $(BONUS_SOURCES_DIR)/main.c \
				$(BONUS_SOURCES_DIR)/do_operations.c \
				$(MANDATORY_SOURCES_DIR)/check_sorted.c 

BONUS_OBJECTS = $(BONUS_SOURCES:%.c=%.o)

MANDATORY_OBJECTS = $(MANDATORY_SOURCES:%.c=%.o)
MANDATORY_OBJECTS_NO_MAIN = $(MANDATORY_SOURCES_NO_MAIN:%.c=%.o)

GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/get_next_line.c \
				$(GET_NEXT_LINE_DIR)/get_next_line_utils.c

GET_NEXT_LINE_OBJECTS = $(GET_NEXT_LINE:%.c=%.o)

all: $(NAME1)

$(NAME1): $(MANDATORY_OBJECTS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(C_FLAGS) $(MANDATORY_OBJECTS) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) -o $(NAME1)

$(NAME2): $(BONUS_OBJECTS) $(MANDATORY_OBJECTS_NO_MAIN) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE_OBJECTS)
	$(CC) $(C_FLAGS) $(BONUS_OBJECTS) $(MANDATORY_OBJECTS_NO_MAIN) $(GET_NEXT_LINE_OBJECTS) $(LIBFT_FLAGS) $(FT_PRINTF_FLAGS) -o $(NAME2)

%.o: %.c
	$(CC) $(C_FLAGS) $(HEADER_FLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all
	@$(MAKE) -C $(LIBFT_DIR) bonus

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR) all

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	rm -f $(MANDATORY_OBJECTS) $(BONUS_OBJECTS) $(GET_NEXT_LINE_OBJECTS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME1) $(NAME2)

re: fclean all

bonus: $(NAME2)

.PHONY: all clean fclean re bonus
