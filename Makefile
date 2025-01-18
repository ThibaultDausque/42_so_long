# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 20:23:59 by tdausque          #+#    #+#              #
#    Updated: 2025/01/18 12:19:09 by tdausque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
#	🌟 GENERAL CONFIG & FLAGS 🌟
# =============================================================================

# Program for compiling C programs
CC := cc
CFLAGS := -Wall -Wextra -Werror -g
INCLUDES := -I./includes
MLX_FILE := libmlx.a
MLX_FLAG := -lX11 -lXext
MLX_PATH := ./minilibx-linux/
MLX_LIB := $(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_EX := $(MLX_LIB) $(MLX_FLAG)
NAME := so_long

# =============================================================================
#	📂 SOURCES & OBJECTS 📂
# =============================================================================

OBJ_DIR := objs

SRCS_SO_LONG := src/game.c src/game_2.c src/main.c \
	src/parse.c src/parse_2.c src/utils.c src/utils_2.c \
	src/window.c src/window_2.c

SRCS_LIBFT := libft/ft_calloc.c libft/ft_bzero.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c \
	libft/ft_atoi.c libft/ft_itoa.c libft/ft_strdup.c libft/ft_split.c libft/ft_strchr.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c \
	libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_strmapi.c libft/ft_substr.c \
	libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_tolower.c libft/ft_toupper.c \
	libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_striteri.c libft/ft_lstnew_bonus.c \
	libft/ft_lstadd_front_bonus.c libft/ft_lstsize_bonus.c libft/ft_lstlast_bonus.c libft/ft_lstadd_back_bonus.c libft/ft_lstdelone_bonus.c
	
SRCS_PRINTF := ft_printf/ft_printf.c \
	ft_printf/ft_print_unbr.c \
	ft_printf/ft_print_str.c \
	ft_printf/ft_print_ptr.c \
	ft_printf/ft_print_nbr.c \
	ft_printf/ft_print_hex.c \
	ft_printf/ft_print_char.c

SRCS_GNL := get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRCS := $(SRCS_SO_LONG) $(SRCS_LIBFT) $(SRCS_PRINTF) $(SRCS_GNL)

OBJS_SO_LONG := $(addprefix $(OBJ_DIR)/, $(SRCS_SO_LONG:.c=.o))
OBJS_LIBFT := $(addprefix $(OBJ_DIR)/, $(SRCS_LIBFT:.c=.o))
OBJS_PRINTF := $(addprefix $(OBJ_DIR)/, $(SRCS_PRINTF:.c=.o))
OBJS_GNL := $(addprefix $(OBJ_DIR)/, $(SRCS_GNL:.c=.o))

OBJS := $(OBJS_GNL) $(OBJS_LIBFT) $(OBJS_PRINTF) $(OBJS_SO_LONG)

# =============================================================================
#	📊 PROGRESS BAR CONFIG 📊
# =============================================================================

BAR_LENGTH := 50
TOTAL_FILES := $(words $(SRCS))
COMPILED_FILES := 0

define progress_bar
	$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES) + 1))))
	$(eval PROGRESS_PERCENT=$(shell echo $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))))
	$(eval FILLED_BAR_LENGTH=$(shell echo $$(($(PROGRESS_PERCENT) * $(BAR_LENGTH) / 100))))
	@printf "\rCompiling [\033[0;32m"
	@for i in $(shell seq 1 $(FILLED_BAR_LENGTH)); do printf "#"; done
	@for i in $(shell seq 1 $(shell echo $$(($(BAR_LENGTH) - $(FILLED_BAR_LENGTH))))); do printf " "; done
	@printf "\033[0m] $(PROGRESS_PERCENT)%%"
endef

# =============================================================================
#	🏗️ RULES 🏗️
# =============================================================================

all: $(NAME)
	@echo "\n🎉 $(NAME) built successfully!"

$(NAME): $(OBJS) mlx
	$(CC) $(OBJS) $(MLX_EX) -o $(NAME)
	@echo "\n🚀 $(NAME) created!"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(call progress_bar)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# -----------------------------------------------------------------------------
# RULES FOR SPECIFIC PARTS
# -----------------------------------------------------------------------------

mlx:
	@make -sC $(MLX_PATH)

libft: $(OBJS_LIBFT)
	@ar rc $(NAME) $(OBJS_LIBFT)
	@ranlib $(NAME)
	@echo "📚 libft part built!"

printf: $(OBJS_PRINTF)
	@ar rc $(NAME) $(OBJS_PRINTF)
	@ranlib $(NAME)
	@echo "🖨️ printf part built!"

gnl: $(OBJS_GNL)
	@ar rc $(NAME) $(OBJS_GNL)
	@ranlib $(NAME)
	@echo "📜 gnl part built!"

# =============================================================================
# CLEANING RULES
# =============================================================================

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -sC $(MLX_PATH)
	@echo "🧹 Object files cleaned!"

fclean: clean
	@rm -f $(NAME)
	@echo "💥 $(NAME) removed!"

re: fclean all
# @echo "🔄 Rebuilding $(NAME)..."

# =============================================================================
# 💼 PHONY RULES 💼
# =============================================================================

.PHONY: all clean fclean re
