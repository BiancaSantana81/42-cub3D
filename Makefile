NAME        := cub3D
NAME_BONUS  := cub3D_bonus
CFLAGS      := -Wextra -Wall -Werror -g3
MAKEFLAGS  += --silent

# LIBRARIES_PATH
LIBMLX      := ./MLX42
LIBFT_PATH  := ./libft
LIBFT       := $(addprefix $(LIBFT_PATH)/, libft.a)

# PATHS
CC          := gcc
SRC_PATH    := sources
SRC_BONUS_PATH := sources_bonus
OBJ_PATH    := objects
OBJ_BONUS_PATH := objects_bonus

# SOURCES
CFILES      :=  main.c init.c utils.c free_memory.c \
                validation/validation.c validation/check_rgb.c validation/data_processing.c validation/map.c validation/map_utils.c validation/check_wall.c \
                graphic/hooks.c graphic/movements.c graphic/images.c graphic/draw_squares.c graphic/wall.c \
                graphic/algorithm.c graphic/setup.c graphic/draw_loop.c

CFILES_BONUS := main_bonus.c init_bonus.c utils_bonus.c free_memory_bonus.c \
                validation_bonus/validation_bonus.c validation_bonus/check_rgb_bonus.c validation_bonus/data_processing_bonus.c validation_bonus/map_bonus.c validation_bonus/map_utils_bonus.c validation_bonus/check_wall_bonus.c \
                graphic_bonus/hooks_bonus.c graphic_bonus/movements_bonus.c graphic_bonus/images_bonus.c graphic_bonus/draw_squares_bonus.c graphic_bonus/wall_bonus.c \
                graphic_bonus/algorithm_bonus.c graphic_bonus/setup_bonus.c graphic_bonus/draw_loop_bonus.c \
				graphic_bonus/minimap/minimap_bonus.c graphic_bonus/minimap/minimap_images_bonus.c

# PATH_FILES
SRCS        := $(addprefix $(SRC_PATH)/, $(CFILES))
OBJS        := $(addprefix $(OBJ_PATH)/, $(CFILES:%.c=%.o))

SRCS_BONUS  := $(addprefix $(SRC_BONUS_PATH)/, $(CFILES_BONUS))
OBJS_BONUS  := $(addprefix $(OBJ_BONUS_PATH)/, $(CFILES_BONUS:%.c=%.o))

# HEADERS
HEADERS     := -I ./includes
HEADERS_BONUS := -I ./includes_bonus
HEADER_FILE := includes/cub.h ./MLX42/include
LIBS_MLX    := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

# COLORS
GREEN       := \033[1;32m
RED         := \033[1;31m
WHITE       := \033[1;37m
YELLOW      := \033[1;33m
BOLD        := \033[1;1m
ORANGE      := \033[38;2;255;165;0m
BLUE        := \033[1;34m
MAGENT      := \033[1;35m
CYAN        := \033[1;36m
RESET       := \033[0m

# LOADING BAR
TOTAL_FILES = $(words $(CFILES))
CURRENT_CFILES = 0

define print_progress
    $(eval CURRENT_FILES=$(shell echo $$(($(CURRENT_FILES)+1))))
    @echo -n "\r$(YELLOW)Progress: $(MAGENT)$(CURRENT_FILES) / $(TOTAL_FILES) [$$((($(CURRENT_FILES) * 100) / $(TOTAL_FILES)))%] $(RESET) : $(CYAN)$(1)$(RESET) "
endef

all: libmlx $(OBJ_PATH) $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER_FILE) | $(OBJ_PATH)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	$(call print_progress, $(BLUE_B)Compiling:$(RESET) $<)
	@echo "                                     "

$(OBJ_BONUS_PATH)/%.o: $(SRC_BONUS_PATH)/%.c $(HEADER_FILE) | $(OBJ_BONUS_PATH)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS_BONUS)
	$(call print_progress, $(BLUE_B)Compiling:$(RESET) $<)
	@echo "                                     "

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_BONUS_PATH):
	@mkdir -p $(OBJ_BONUS_PATH)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBS_MLX) $(LIBFT) $(LFLAGS) $(HEADERS) -o $(NAME) -lm
	@echo "                                     "
	@echo "$(GREEN) 🟥🟧🟨🟩🟦🟪🟥🟧🟨🟩🟦🟪🟥🟧🟨🟩🟦🟪🟥"
	@echo "$(WHITE) 🟧  The [$(RED)C$(ORANGE)U$(YELLOW)B$(CYAN)3$(GREEN)D$(WHITE)] has been compiled!  🟧"
	@echo "$(GREEN) 🟥🟧🟨🟩🟦🟪🟥🟧🟨🟩🟦🟪🟥🟧🟨🟩🟦🟪🟥"
	@echo "                                     "

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(LIBS_MLX) $(LIBFT) $(LFLAGS) $(HEADERS_BONUS) -o $(NAME_BONUS) -lm
	@echo "                                     "
	@echo "$(GREEN) 🟥🟧🟨🟩🟦🟪🟥🟧🟨🟩🟦🟪🟥🟧🟨🟩🟦🟪🟥"
	@echo "$(WHITE) 🟧  The [$(RED)C$(ORANGE)U$(YELLOW)B$(CYAN)3$(GREEN)D BONUS$(WHITE)] has been compiled!  🟧"
	@echo "$(GREEN) 🟥🟧🟨🟩🟦🟪🟥🟧🟨🟩🟦🟪🟥🟧🟨🟩🟦🟪🟥"
	@echo "                                     "

clean:
	@rm -rf $(OBJ_PATH)
	@rm -rf $(OBJ_BONUS_PATH)
	@echo "                                     "
	@echo " 🟥 🟧 🟨 🟩 🟦 🟪 🟥 🟧 🟨 🟩 🟦 🟪 🟥"
	@echo " 🟧                                  🟧"
	@echo " 🟨    $(WHITE)Objects - $(RED)C$(ORANGE)U$(YELLOW)B$(CYAN)3$(GREEN)D$(WHITE) - cleaned     🟨"
	@echo " 🟩                                  🟩"

fclean: clean
	@echo " 🟦 $(WHITE)         Cleaning all... 🧹      🟦"
	@echo " 🟪                                  🟪"
	@rm -rf $(NAME) $(NAME_BONUS)
	@rm -rf $(LIBMLX)/build
	@make fclean -C $(LIBFT_PATH)
	@echo " 🟥$(WHITE) Cleaning -$(RED)C$(ORANGE)U$(YELLOW)B$(CYAN)3$(GREEN)D$(WHITE) & BONUS complete! 🟥"
	@echo " 🟧                                  🟧"
	@echo " 🟥 🟧 🟨 🟩 🟦 🟪 🟥 🟧 🟨 🟩 🟦 🟪 🟥"
	@echo "                                     "

val: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all -q ./$(NAME)

clear:
	clear
	$(MAKE) all

bonus: $(OBJ_BONUS_PATH) $(NAME_BONUS)

re: fclean all

re_bonus: fclean bonus

.PHONY: all, clean, fclean, re, libmlx, bonus, re_bonus
