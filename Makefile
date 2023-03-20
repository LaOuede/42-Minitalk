# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 12:57:00 by gle-roux          #+#    #+#              #
#    Updated: 2023/03/20 12:00:56 by gle-roux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                          BANNER & COLOR SETINGS                              #
#------------------------------------------------------------------------------#

#Banner
define BANNER1
                                                  
$G                     $Y_$G       $Y_$G _        _ _    
$G               /\/\ $Y(_)$G_ __ $Y(_)$G |_ __ _| | | __
$G              /    \| | '_ \| | __/ _` | | |/ /
$C          ___/ /\/\ \ | | | | | || (_| | |   <____
$C         /____/    \/_|_| |_|_|\__\__,_|_|_|\____/
$C                                    
endef
export BANNER1

# Colors settings
R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
Y = $(shell tput -Txterm setaf 3)
Z = $(shell tput -Txterm setaf 5)
C = $(shell tput -Txterm setaf 6)
W = $(shell tput -Txterm setaf 7)

#------------------------------------------------------------------------------#
#                                   TOOLS                                      #
#------------------------------------------------------------------------------#
define HELP
$Z---------------------------------------------------------------
$YTools available$Z
make help		$Y->$Z Display tools available
make map		$Y->$Z Display mind map
make norm		$Y->$Z Run Norminette
make text		$Y->$Z Open text generator
make pdf 		$Y->$Z Open PDF subject
---------------------------------------------------------------
endef
export HELP

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	= 	-g -Wall -Wextra -Werror

# Remove and Archives
ARCH	=	ar rcs
RM		=	rm -rf

# Librairies names
NAME		=
CLIENT		=	client
SERVER		=	server

# Dir. and files names
SRCS_C_DIR	=	./src_client/
SRCS_C_LIST	=	client.c
SRCS_C		=	$(addprefix $(SRCS_C_DIR), $(SRCS_C_LIST))

SRCS_S_DIR	=	./src_server/
SRCS_S_LIST	=	server.c \
				utils_s.c
SRCS_S		=	$(addprefix $(SRCS_S_DIR), $(SRCS_S_LIST))

OBJS_DIR	=	./obj/
OBJS_C_LIST	=	$(patsubst %.c, %.o, $(SRCS_C_LIST))
OBJS_C		=	$(addprefix $(OBJS_DIR), $(OBJS_C_LIST))
OBJS_S_LIST	=	$(patsubst %.c, %.o, $(SRCS_S_LIST))
OBJS_S		=	$(addprefix $(OBJS_DIR), $(OBJS_S_LIST))

HEADER_DIR	=	./includes/
HEADER_LIST	=	minitalk.h
HEADER	 	=	$(addprefix $(HEADER_DIR), $(HEADER_LIST))

# Libft variables
LIBFT_DIR	=	./libft/
LIBFT		=	$(LIBFT_DIR)libft.a
LIBFT_H		=	$(LIBFT_DIR)includes/libft.h

# Printf variables
PRINTF_DIR	=	./ft_printf/
PRINTF		=	$(PRINTF_DIR)printf.a
PRINTF_H	=	$(PRINTF_DIR)includes/ft_printf.h

# Evaluator variable
USER		=	$(shell whoami)

#------------------------------------------------------------------------------#
#                                  RULES                                       #
#------------------------------------------------------------------------------#

# Executable creation
all: dir $(CLIENT) $(SERVER)
	@echo $Y"$$BANNER1"$W
	@echo "				$Z...made by $Ygle-roux$Z$W🐭"
	@echo "					$Z...evaluated by $Y$(USER)\n\n$W"

#Create directory for *.o files
dir:
	@mkdir -p $(OBJS_DIR)

# Compilation
$(CLIENT): $(OBJS_C)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@$(CC) $(CFLAGS) $(SRCS_C) $(LIBFT) $(PRINTF) -o $(CLIENT)

$(SERVER): $(OBJS_S)
	@echo "\n\n$W--------------------- $Zminitalk is $Gdone ✅ $W---------------------"
	@echo "\n$W-------------------------- $Zlibft.a $W----------------------------"
	@make -C $(LIBFT_DIR)
	@echo "\n$W-------------------------- $Zprintf.a $W---------------------------"
	@make -C $(PRINTF_DIR)
	@$(CC) $(CFLAGS) $(SRCS_S) $(LIBFT) $(PRINTF) -o $(SERVER)
	@echo "\n-------------- $ZIf help is needed, type $Ymake help $W--------------"
	@echo "\n>>>>>>>>>>>>>>>>>>>>> $ZMINITALK is $Gready ✅$W <<<<<<<<<<<<<<<<<<<<"

# Create all files .o (object) from files .c (source code)
$(OBJS_DIR)%.o: $(SRCS_C_DIR)%.c $(HEADER)
	@printf "\n $GCompiling : $Z$(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)%.o: $(SRCS_S_DIR)%.c $(HEADER)
	@printf "\n $GCompiling : $Z$(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Remove objects
clean:
	@echo "\n\n$W>>>>>>>>>>>>>>>>>>>>>>>>>>> $YCLEANING $W<<<<<<<<<<<<<<<<<<<<<<<<<<"
	@$(RM) $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@echo "$W------------ $Zclient & server : $(OBJS_DIR) was $Rdeleted ❌$W-----------"

# Remove executables
fclean: clean
	@$(RM) $(SERVER) $(CLIENT) $(LIBFT) $(PRINTF)
	@echo "\n$W-------- $ZAll exec. and archives successfully $Rdeleted ❌$W--------\n"
	@echo "$W>>>>>>>>>>>>>>>>>>>>> $ZCleaning is $Gdone ✅ $W<<<<<<<<<<<<<<<<<<<<<\n\n"

# Remove objects and executables and remake
re: fclean
	@$(MAKE) all

# Display tools available
help:
	@echo "$$HELP"

# Open the subject
pdf:
	@open https://cdn.intra.42.fr/pdf/pdf/58187/fr.subject.pdf

# Open a text generator
text:
	@open https://www.dummytextgenerator.com/#jump

# Open a character generator
test:
	@open https://www.browserling.com/tools/text-repeat

# Run norminette
norm :
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>>>> $YNORMINETTE $W<<<<<<<<<<<<<<<<<<<<<<<<<<$Z\n"
	@norminette $(SRCS) $(HEADER) $(LIBFT_DIR) $(PRINTF_DIR) $(SRCS_C_DIR) $(SRCS_S_DIR)
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>> $YNORMINETTE ✅ $W<<<<<<<<<<<<<<<<<<<<<<<<<<"

# Avoids file-target name conflicts
.PHONY: all dir clean fclean re help pdf text test norm