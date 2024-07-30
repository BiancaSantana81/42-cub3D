NAME		:= cub3D
CFLAGS		:= -Wextra -Wall -Werror -g3
MAKEFLAGS += --silent

# LIBRARIES_PATH
LIBMLX		:= ./MLX42
LIBFT_PATH	:= ./libft
LIBFT		:= $(addprefix $(LIBFT_PATH)/, libft.a)

# PATHS
CC			:= gcc
SRC_PATH 	:= sources
OBJ_PATH	:= objects

# SOURCES
CFILES		:=  trash.c main.c validation.c check_rgb.c data_processing.c 1_map.c 2_map.c utils.c init.c wall.c\

#PATH_FILES
SRCS		:= $(addprefix $(SRC_PATH)/, $(CFILES))
OBJS		:= $(addprefix $(OBJ_PATH)/, $(CFILES:%.c=%.o))

#HEADERS
HEADERS		:= -I ./includes
HEADER_FILE := includes/cub.h ./MLX42/include
LIBS_MLX	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

# COLORS
GREEN	:=	\033[1;32m
RED		:=	\033[1;31m
WHITE	:=	\033[1;37m
YELLOW	:=	\033[1;33m
BOLD	:=	\033[1;1m
ORANGE	:=	\033[38;2;255;165;0m
BLUE	:=	\033[1;34m
MAGENT	:=	\033[1;35m
CYAN	:=	\033[1;36m
RESET	:=	\033[0m

#LOADING BAR
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
	@$(CC) $(CFLAGS) -o $@ -c $<
	$(call print_progress, $(BLUE_B)Compiling:$(RESET) $<)
	@echo "                                     "

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBS_MLX) $(LIBFT) $(LFLAGS) $(HEADERS) -o $(NAME)
	@echo "                                     "
	@echo "$(GREEN) 🟥🟧🟨🟩🟦🟪🟥🟧🟨🟩🟦🟪🟥🟧🟨🟩🟦🟪🟥"
	@echo "$(WHITE) 🟧  The [$(RED)C$(ORANGE)U$(YELLOW)B$(CYAN)3$(GREEN)D$(WHITE)] has been compiled!  🟧"
	@echo "$(GREEN) 🟥🟧🟨🟩🟦🟪🟥🟧🟨🟩🟦🟪🟥🟧🟨🟩🟦🟪🟥"
	@echo "                                     "

clean:
	@rm -rf $(OBJ_PATH)
	@echo "                                     "
	@echo " 🟥 🟧 🟨 🟩 🟦 🟪 🟥 🟧 🟨 🟩 🟦 🟪 🟥"
	@echo " 🟧                                  🟧"
	@echo " 🟨    $(WHITE)Objects - $(RED)C$(ORANGE)U$(YELLOW)B$(CYAN)3$(GREEN)D$(WHITE) - cleaned     🟨"
	@echo " 🟩                                  🟩"

fclean: clean
	@echo " 🟦 $(WHITE)         Cleaning all... 🧹      🟦"
	@echo " 🟪                                  🟪"
	@rm -rf $(NAME)
	@rm -rf $(LIBMLX)/build
	@make fclean -C $(LIBFT_PATH)
	@echo " 🟥$(WHITE)   Cleaning - $(RED)C$(ORANGE)U$(YELLOW)B$(CYAN)3$(GREEN)D$(WHITE) - complete!   🟥"
	@echo " 🟧                                  🟧"
	@echo " 🟥 🟧 🟨 🟩 🟦 🟪 🟥 🟧 🟨 🟩 🟦 🟪 🟥"
	@echo "                                     "

val: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all -q ./$(NAME)

clear:
	clear
	$(MAKE) all

re: fclean all

.PHONY: all, clean, fclean, re, libmlx
