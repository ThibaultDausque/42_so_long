# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 20:23:59 by tdausque          #+#    #+#              #
#    Updated: 2025/01/12 17:33:27 by tdausque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
#	🌟 GENERAL CONFIG & FLAGS 🌟
# =============================================================================

# Program for compiling C programs
CC := cc
CFLAGS := -Wall -Wextra -Werror
INCLUDES := -I./includes
FT_PRINTF := ft_printf/ft_printf.a
LIBFT := lib/libft.a
GNL := get_next_line/get_next_line.a
INCLUDE := -I INCLUDE

NAME := so_long

# =============================================================================
#	📂 SOURCES & OBJECTS 📂
# =============================================================================

SRCS_SO_LONG = src/game.c src/game_2.c src/main.c \
	src/parse.c src/parse_2.c src/utils.c src/utils_2.c \
	src/window.c src/window_2.c

SRC := $(SRCS_SO_LONG)

OBJ_DIR := objs
OBJS := $(SRC:%.c=$(OBJ_DIR)/%.o)

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

all: libft ft_printf get_next_line $(NAME)
	@echo "\n🎉 $(NAME) built successfully!"

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(GNL)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\n🚀 $(NAME) created!"

$(OBJ_PATH)/%.o: %.c
	@mkdir -p $(dir $@)
	$(call progress_bar)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


# =============================================================================
# LIBFT
# =============================================================================

$(LIBFT):
	@cd libft && make --no-print-directory

# =============================================================================
# FT_PRINTF
# =============================================================================

$(FT_PRINTF):
	@cd ft_printf && make --no-print-directory

# =============================================================================
# GET_NEXT_LINE
# =============================================================================
GNL_SRCS := get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

$(GNL):
	@cd get_next_line && cc $(GNL_SRCS) 

# =============================================================================
# CLEANING RULES
# =============================================================================

clean:
	@rm -rf $(OBJ_PATH)
	@echo "🧹 Object files cleaned!"

fclean: clean
	@rm -f $(NAME)
	@echo "💥 $(NAME) removed!"

re: fclean all
	@echo "🔄 Rebuilding $(NAME)..."

# =============================================================================
# 💼 PHONY RULES 💼
# =============================================================================

.PHONY: all clean fclean re
