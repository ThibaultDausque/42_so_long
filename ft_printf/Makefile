# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 16:25:54 by tdausque          #+#    #+#              #
#    Updated: 2025/01/12 17:31:13 by tdausque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
#	🌟 GENERAL CONFIG & FLAGS 🌟
# =============================================================================

# Program for compiling C programs
CC := cc
CFLAGS := -Wall -Wextra -Werror
INCLUDES := -I./includes

NAME := ft_printf.a

# =============================================================================
#	📂 SOURCES & OBJECTS 📂
# =============================================================================

OBJ_PATH := ./objs

SRCS_PRINTF = ft_printf.c \
	ft_print_unbr.c \
	ft_print_str.c \
	ft_print_ptr.c \
	ft_print_nbr.c \
	ft_print_hex.c \
	ft_print_char.c	

SRCS := $(SRCS_PRINTF)

OBJS_PRINTF := $(addprefix $(OBJ_PATH)/, $(SRCS_PRINTF:.c=.o))

OBJS := $(OBJS_PRINTF)

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
	@printf "\rCompiling ft_printf [\033[0;32m"
	@for i in $(shell seq 1 $(FILLED_BAR_LENGTH)); do printf "#"; done
	@for i in $(shell seq 1 $(shell echo $$(($(BAR_LENGTH) - $(FILLED_BAR_LENGTH))))); do printf " "; done
	@printf "\033[0m] $(PROGRESS_PERCENT)%%"
endef

# =============================================================================
#	🏗️ RULES 🏗️
# =============================================================================

all: $(NAME)
	@echo "\n🎉 $(NAME) OK"

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\n🚀 $(NAME) OK"

$(OBJ_PATH)/%.o: %.c
	@mkdir -p $(dir $@)
	$(call progress_bar)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# -----------------------------------------------------------------------------
# RULES FOR SPECIFIC PARTS
# -----------------------------------------------------------------------------

libft: $(OBJS_LIBFT)
	@ar rc $(NAME) $(OBJS_LIBFT)
	@ranlib $(NAME)
	@echo "📚 libft part built!"

# -----------------------------------------------------------------------------
# CLEANING RULES
# -----------------------------------------------------------------------------

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
