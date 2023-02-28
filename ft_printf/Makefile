# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 12:57:00 by gle-roux          #+#    #+#              #
#    Updated: 2023/02/27 10:26:46 by gle-roux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	= 	-Wall -Wextra -Werror

# Remove and Archives
RM		=	rm -rf
ARCH	=	ar rcs	

# Dir and file names
NAME		=	printf.a

SRCS_DIR	=	./src/
SRCS_LIST	=	ft_len.c \
				ft_printf.c \
				ft_print_utils.c \
				ft_type.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_DIR	=	./obj/
OBJS_LIST	=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

HEADER_DIR	=	./includes/
HEADER_LIST	=	ft_printf.h
HEADER	 	=	$(addprefix $(HEADER_DIR), $(HEADER_LIST))

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

# Colors settings
R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
Y = $(shell tput -Txterm setaf 3)
Z = $(shell tput -Txterm setaf 5)
C = $(shell tput -Txterm setaf 6)
W = $(shell tput -Txterm setaf 7)

# Creation of the executable
all: dir $(NAME)

# Compile library
$(NAME): $(OBJS)
	@$(ARCH) $(NAME) $(OBJS)
	@echo "\n\n$W----------------------- $Zprintf is $Gdone ✅$W ----------------------"
	
# Create all files .o (object) from files .c (source code)
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	@printf "\n $GCompiling : $Z$(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

#Create directory for *.o files
dir:
	@mkdir -p $(OBJS_DIR)

# Removes objects
clean:
	@$(RM) $(OBJS_DIR)
	@echo "$W--------------- $Z$(NAME) : $(OBJS_DIR) was $Rdeleted ❌$W---------------\n"

# Removes all objects and executables
fclean: clean
	@$(RM) $(NAME)
	@echo "$W-------- $ZAll exec. and archives successfully $Rdeleted ❌$W--------"

# Removes objects and executables and remake
re: fclean all
	@$(MAKE) all

# Avoids file-target name conflicts
.PHONY: all dir clean fclean re