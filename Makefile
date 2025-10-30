# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 13:07:54 by kebris-c          #+#    #+#              #
#    Updated: 2025/09/08 16:08:16 by kebris-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

.DEFAULT:
	@echo ""
	@echo "❌ Unknown target: '$@'"
	@echo "If you want to know what rules are available and "
	@echo "what the hell they do, then run: make help"
	@echo ""

.PHONY: all clean fclean re

# 📚 Basic project variables
#
NAME	= $(notdir $(shell pwd)).a
PROJECT	= $(notdir $(shell pwd))

# 🔧 Compiler and flags
#
CC		= cc
FLAGS	= -Wall -Wextra -Werror
E_FLAGS	= \
			$(CFLAGS) \
			-MMD \
			-MP \
			-std=c17 \
			-Wpedantic \
			-Wconversion \
			-Wsign-conversion \
			-Wshadow \
			-Wstrict-prototypes \
			-Wpointer-arith \
			-Wcast-align \
			-Wunreachable-code \
			-Winit-self \
			-Wswitch-enum \
			-Wfloat-equal \
			-Wformat=2 \
			-Wmissing-prototypes \
			-Wmissing-declarations \
			-Wdouble-promotion \
			-Wundef \
			-Wbad-function-cast \
			-Winline -Wvla \
			-Wno-unused-parameter \
			-Wno-missing-field-initializers \
			-fstrict-aliasing \
			-fstack-protector-strong \
			-D_FORTIFY_SOURCE=2 \
			-g3 \
			-O0

# 🔨 Tools
#
AR      = ar rcs
RM      = rm -rf
NORM    = norminette
CP      = cp -r
LS		= ls -l

# 📂 Fast path variables / dirs
#
SRC_DIR		= src/
INCLUDE_DIR	= include/
OBJS_DIR	= objs/
DEPS_DIR	= deps/
# If there is bonus
#
BONUS_DIR		= bonus/
B_SRC_DIR		= bonus/src/
B_INCLUDE_DIR	= bonus/include/
B_OBJS_DIR		= bonus/objs/
B_DEPS_DIR		= bonus/deps/
# If there is Libft
#
LIB_DIR			= libft/
L_SRC_DIR		= libft/src/
L_INCLUDE_DIR	= libft/include/
L_OBJS_DIR		= libft/objs/
L_DEPS_DIR		= libft/deps/

# 🎯 Objects and Deps
#
SRCS	= $(notdir $(wildcard $(SRC_DIR)*.c))
OBJS	= $(patsubst %.c,$(OBJS_DIR)%.o,$(SRCS))
DEPS	= $(patsubst $(OBJS_DIR)%.o,$(DEPS_DIR)%.d,$(OBJS))
# If there is bonus
#
B_SRCS	= $(notdir $(wildcard $(B_SRC_DIR)*.c))
B_OBJS	= $(patsubst %.c,$(B_OBJS_DIR)%.o,$(B_SRCS))
B_DEPS	= $(patsubst $(B_OBJS_DIR)%.o,$(B_DEPS_DIR)%.d,$(B_OBJS))

# 📄 Headers. First, we need to check if there is a libft dir
#
HAS_LIBFT = $(shell \
    if [ -d libft ]; then \
        echo yes; \
    else \
        echo no; \
    fi)
HEADERS = -I$(INCLUDE_DIR)
ifeq ($(HAS_LIBFT),yes)
    HEADERS += -I$(L_INCLUDE_DIR)
endif

# ------------------------------------------------ #
#    COMPILE COMMANDS 			                   #
# ------------------------------------------------ #

define COMPILE_PROJECT
	@if $(NORM) $(SRC_DIR) 2>/dev/null; then \
		if [ -d $(LIB_DIR) ]; then \
			$(CC) $(1) $(2) $(HEADERS) -L$(LIB_DIR) -lft -o $(PROJECT); \
		else \
			$(CC) $(1) $(2) $(HEADERS) -o $(PROJECT); \
		fi; \
	else \
		exit 1; \
	fi
endef

# ------------------------------------------------ #
#  Setup rule: normalize project structure         #
# ------------------------------------------------ #

setup:
	@mkdir -p $(SRC_DIR) $(INCLUDE_DIR) $(OBJS_DIR) $(DEPS_DIR)
	@if [ -d $(BONUS_DIR) ]; then \
		mkdir -p $(B_SRC_DIR) $(B_INCLUDE_DIR) $(B_OBJS_DIR) $(B_DEPS_DIR); \
		find . -maxdepth 1 -name "*_bonus.c" ! -path "./$(B_SRC_DIR)*" -exec mv -n {} $(B_SRC_DIR)/ \;; \
		find . -maxdepth 1 -name "*_bonus.h" ! -path "./$(B_INCLUDE_DIR)*" -exec mv -n {} $(B_INCLUDE_DIR)/ \;; \
		find . -maxdepth 1 -name "*_bonus.o" ! -path "./$(B_OBJS_DIR)*" -exec mv -n {} $(B_OBJS_DIR)/ \;; \
		find . -maxdepth 1 -name "*_bonus.d" ! -path "./$(B_DEPS_DIR)*" -exec mv -n {} $(B_DEPS_DIR)/ \;; \
	fi
	@find . -maxdepth 1 -name "*.c" ! -path "./$(SRC_DIR)*" -exec mv -n {} $(SRC_DIR)/ \;
	@find . -maxdepth 1 -name "*.h" ! -path "./$(INCLUDE_DIR)*" -exec mv -n {} $(INCLUDE_DIR)/ \;
	@find . -maxdepth 1 -name "*.o" ! -path "./$(OBJS_DIR)*" -exec mv -n {} $(OBJS_DIR)/ \;
	@find . -maxdepth 1 -name "*.d" ! -path "./$(DEPS_DIR)*" -exec mv -n {} $(DEPS_DIR)/ \;

# Make sure this rule is updated with correct data
#
help:
	@echo ""
	@echo "==================== HELP ===================="
	@echo ""
	@echo "Try to run make followed by one of the following rule you want"
	@echo "Example: make clean"
	@echo ""
	@echo "📦 Basic build:"
	@echo "  all           -> setup, build $(NAME). Default option used by make"
	@echo "  bonus         -> build $(NAME) with bonus sources"
	@echo "  clean         -> remove object and dependency files"
	@echo "  fclean        -> clean + remove $(NAME) and executable"
	@echo "  re            -> fclean + all"
	@echo ""
	@echo "⚡ Project compilation:"
	@echo "  $(PROJECT)			-> compile main project"
	@echo "  bonus_$(PROJECT)	-> compile bonus project"
	@echo "  rigor				-> compile main project with rigurous flags"
	@echo "  bonus_rigor		-> compile bonus project with rigurous flags"
	@echo ""
	@echo "🛠 Norminette & leaks:"
	@echo "  norm         -> run norminette on project"
	@echo "  leaks         -> run valgrind on project"
	@echo ""
	@echo "📁 Git ignore automation:"
	@echo "  ignore        -> generate .gitignore (keeps sources, ignores binaries and deps)"
	@echo "  ignoremake    -> modify .gitignore to ignore Makefile too"
	@echo ""
	@echo "==============================================="
	@echo ""

#------------------------------------------------#
#   BASIC RULES / LIBRARY COMMANDS               #
#------------------------------------------------#

all: setup $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "✅ $(NAME) built with main sources"

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	@echo "🔨 Compiling $<..."
	@if [ -d $(LIB_DIR) ]; then \
		$(MAKE) -C $(LIB_DIR); \
	fi
	@$(CC) $(FLAGS) -MMD -MP $(HEADERS) -c $< -o $@
	@mv $(OBJS_DIR)$*.d $(DEPS_DIR)

bonus: $(B_OBJS)
	@$(AR) $(NAME) $(B_OBJS)
	@echo "✅ $(NAME) build with bonus sources"; \

$(B_OBJS_DIR)%.o: $(B_SRC_DIR)%.c
	@echo "🔨 Compiling bonus $<..."
	@if [ -d $(LIB_DIR) ]; then \
		$(MAKE) -C $(LIB_DIR); \
	fi
	@$(CC) $(FLAGS) $(HEADERS) -c $< -o $@
	@mv $(B_OBJS_DIR)$*.d $(B_DEPS_DIR)

clean:
	@$(RM) $(OBJS) $(B_OBJS) $(DEPS) $(B_DEPS)

fclean: clean
	@$(RM) $(NAME) $(PROJECT)

re: fclean all

#------------------------------------------------#
#   PROJECT COMPILATION                          #
#------------------------------------------------#

$(PROJECT): $(OBJS)
	$(call COMPILE_PROJECT,$(E_FLAGS),$(OBJS))

bonus_$(PROJECT): $(B_OBJS)
	$(call COMPILE_PROJECT,$(E_FLAGS),$(B_OBJS))

rigor: $(OBJS)
	$(call COMPILE_PROJECT,$(E_FLAGS),$(OBJS))
    
bonus_rigor: $(B_OBJS)
	$(call COMPILE_PROJECT,$(E_FLAGS),$(B_OBJS))

#------------------------------------------------#
#   NORMINETTE & LEAKS                           #
#------------------------------------------------#

norm:
	@if $(NORM) $(CURDIR) 2>/dev/null; then \
		exit 0; \
	else \
		exit 1; \
	fi

leaks: $(PROJECT)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(PROJECT) || true

# Include dependency files if they exist
#
-include $(wildcard $(DEPS))
-include $(wildcard $(B_DEPS))

