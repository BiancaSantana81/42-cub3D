# Colors to print message
GREEN := \033[1;32m
WHITE := \033[1;37m

# Executable name
NAME	:= cub3D

# Flags
CFLAGS	:=  -g -Wextra -Wall -Werror

# Libraries path
LIBMLX	:= ./MLX42
LIBFT_PATH := ./libft/
LIBFT := $(addprefix $(LIBFT_PATH), libft.a)

# Files

# Source directory where .c files are located
SRC_DIR:= src

# List of source files
FILES_SRC := game.c map.c validations.c flood_fill.c images_draw.c images_put.c hooks.c updates.c  map_utils.c

# List of object files derived from source files
FILES_SRC_O := $(FILES_SRC:.c=.o)

# List of header files directories
HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)

# List of libraries to link against
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

# Get the list of source files with the correct path
SRCS	:= $(addprefix $(SRC_DIR)/, $(FILES_SRC))
OBJS	:= ${addprefix $(SRC_DIR)/, $(FILES_SRC_O)}

# Compile MLX library
all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# Compile LIBFT library
$(LIBFT):
	@make -C $(LIBFT_PATH)

# Compile .c file into .o file
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

# Build the final executable
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)\nCompilation complete! Use the so_long executable to start playing!"
	
# Clean object files
clean:
	@rm -rf $(OBJS)

# Clean everything (including temporary build artifacts)
fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBMLX)/build
	@make fclean -C$(LIBFT_PATH)
	@echo "$(WHITE)\nCleaning - SO LONG - completed!"

# Clean and rebuild everything
re: clean all

# Targets that are not associated with files
.PHONY: all, clean, fclean, re, libmlx, libft