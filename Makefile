# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmanzano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 13:32:23 by cmanzano          #+#    #+#              #
#    Updated: 2021/12/29 11:35:23 by chris            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ECHO IS DIFFERENT IN LUNUX
ifeq ($(shell uname), Linux)
ECHO = echo -e
else
ECHO = echo
endif

# COLOR
GREEN = $(ECHO) "\033[0;32m" #;4 underline
BLUE = $(ECHO) "\033[0;34m" 
PURPLE = $(ECHO) "\033[0;35m"
CYAN = $(ECHO) "\033[0;36m"
RESET = "\033[1;0m"

# ENSAMBLER
AR = ar
AR_FLAGS = crs

# COMPILER
CC = gcc
CFLAGS = -Wall -Werror -Wextra

#FILENAME
NAME =	pipex

# INCLUDE FILES
INC_DIR = inc

# SOURCE FILES
SRC_DIR = src
OBJ_DIR = obj
SRC = 	main.c
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))

# MODULES
LIBFT = libft.a
LIBFT_DIR = libft

all:  init_submodules $(OBJ_DIR) $(NAME)

init_submodules:
	@if [ ! -f "$(LIBFT_DIR)/Makefile" ]; then\
		$(PURPLE)CLONING SUBMODULES$(RESET);\
		git submodule update --init --recursive;\
	fi

$(NAME): $(LIBFT_DIR)/$(LIBFT) $(OBJS)
	@$(BLUE) Compiling objects with the $(LIBFT_DIR)/$(LIBFT) into $(NAME) $(RESET)
	@$(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) $(OBJS) -o $(NAME)
	@$(GREEN) Done! $(RESET)

$(LIBFT_DIR)/$(LIBFT): init_submodules
	@make -sC $(LIBFT_DIR)
	@$(ECHO)
	@$(PURPLE)COMPILING $(NAME) $(RESET)

debug: $(OBJS)
	@$(ECHO)
	@$(PURPLE) COMPILING $(NAME) $(RESET)
	@$(CC) $(LIBFT_DIR)/$(LIBFT) $< -o $(NAME)


$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c 
	@$(CYAN) Compiling $< $(RESET)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(PURPLE)CLEANED $(RESET)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -sC $(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)


.PHONY: all clean fclean re init_submodules $(OBJ_DIR)/%.o 
