# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdausque <tdausque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/11 11:03:14 by tdausque          #+#    #+#              #
#    Updated: 2025/01/12 17:31:02 by tdausque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
#	🌟 GENERAL CONFIG & FLAGS 🌟
# =============================================================================

# Program for compiling C programs
CC := cc
CFLAGS := -Wall -Wextra -Werror
INCLUDES := -I./includes

NAME := libft.a

# =============================================================================
#	📂 SOURCES & OBJECTS 📂
# =============================================================================

OBJ_PATH := ./objs

SRCS_LIBFT := ft_calloc.c ft_bzero.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_atoi.c ft_itoa.c ft_strdup.c ft_split.c ft_strchr.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_strmapi.c ft_substr.c \
	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_striteri.c ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c
	

SRCS := $(SRCS_LIBFT)

OBJS_LIBFT := $(addprefix $(OBJ_PATH)/, $(SRCS_LIBFT:.c=.o))

OBJS := $(OBJS_LIBFT)

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
	@printf "\rCompiling libft [\033[0;32m"
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
