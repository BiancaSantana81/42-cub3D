# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 11:41:34 by bda-mota          #+#    #+#              #
#    Updated: 2024/08/08 14:42:46 by bsantana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a
SRC_DIR	:= src
OBJ_DIR	:= obj

MAKEFLAGS	+= --silent
CC		:= cc
FLAGS	:= -Wall -Werror -Wextra -g3
HEADER	:= -I ./src

CFILES	:= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
			ft_strdup.c ft_strlcat.c ft_strlcpy.c  ft_strcpy.c  ft_strncpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
			ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_special_split.c \
			ft_striteri.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_atol.c \
			ft_free_matrix.c ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstsize.c \
			ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_strcmp.c ft_strcat.c ft_issign.c ft_strcspn.c \
			get_next_line.c get_next_line_utils.c ft_isspace.c ft_strnchr.c ft_strndup.c ft_strstr.c ft_printf_fd.c ft_print_matrix.c \
			add_vector.c create_vector.c mult_vector.c mag.vector.c copy_vector.c rotate_vector.c

SRC		:= $(addprefix $(SRC_DIR)/, $(CFILES))
OBJS	:= $(addprefix $(OBJ_DIR)/, $(notdir $(CFILES:%.c=%.o)))

PURPLE	:=	\033[1;35m
GREEN	:=	\033[1;32m
RED		:=	\033[1;31m
WHITE	:=	\033[1;37m
BOLD	:=	\033[1;1m

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) -o $@ -c $< $(HEADER)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
