# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 12:57:00 by gle-roux          #+#    #+#              #
#    Updated: 2023/03/02 15:45:10 by gle-roux         ###   ########.fr        #
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
#                                   TESTS                                      #
#------------------------------------------------------------------------------#

# For testing purposes only
TEST1_ARGS = "3 1 2"
TEST2_ARGS = 4 7 2
TEST3_ARGS = -18 47 65
TEST4_ARGS = 5 2 -3
TEST5_ARGS = 3 3 2
TEST6_ARGS = 3 A 2

#------------------------------------------------------------------------------#
#                                   TOOLS                                      #
#------------------------------------------------------------------------------#
define HELP
$Z---------------------------------------------------------------
$YTools available$Z
make help		$Y->$Z Display tools available
make map		$Y->$Z Display mind map
make mem		$Y->$Z Run test with leaks -atExit command
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
CFLAGS	= 	-Wall -Wextra -Werror

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
SRCS_S_LIST	=	server.c
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

# Creation of the executable
all: dir $(CLIENT) $(SERVER)
	@echo $Y"$$BANNER1"$W
	@echo "				$Z...made by $Ygle-roux$Z$W"
	@echo "					$Z...evaluated by $Y$(USER)\n\n$W"

# Compile
$(CLIENT): $(OBJS_C)
	@$(CC) $(CFLAGS) $(SRCS_C) -o $(CLIENT)

$(SERVER): $(OBJS_S)
	@echo "\n\n$W---------------------- $Zminitalk is $Gdone ✅ $W---------------------"
	@echo "\n$W--------------------------- $Zlibft.a $W----------------------------"
	@make -C $(LIBFT_DIR)
	@echo "\n$W-------------------------- $Zprintf.a $W---------------------------"
	@make -C $(PRINTF_DIR)
	@$(CC) $(CFLAGS) $(SRCS_S) $(LIBFT) $(PRINTF) -o $(SERVER)
	@echo "\n-------------- $ZIf help is needed, type $Ymake help $W--------------"
	@echo "\n>>>>>>>>>>>><>>>>>>>> $ZMINITALK is $Gready ✅$W <<<<<<<<<<<<<<<<<<<<"

# Create all files .o (object) from files .c (source code)
$(OBJS_DIR)%.o: $(SRCS_C_DIR)%.c $(HEADER)
	@printf "\n $GCompiling : $Z$(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)%.o: $(SRCS_S_DIR)%.c $(HEADER)
	@printf "\n $GCompiling : $Z$(notdir $<)"
	@$(CC) $(CFLAGS) -c $< -o $@

#Create directory for *.o files
dir:
	@mkdir -p $(OBJS_DIR)

# Removes objects
clean:
	@echo "\n\n$W>>>>>>>>>>>>>>>>>>>>>>>>>>> $YCLEANING $W<<<<<<<<<<<<<<<<<<<<<<<<<<"
	@$(RM) $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@echo "$W------------ $Zclient & server : $(OBJS_DIR) was $Rdeleted ❌$W-----------"

# Removes executables
fclean: clean
	@$(RM) $(SERVER) $(CLIENT) $(LIBFT) $(PRINTF)
	@echo "\n$W-------- $ZAll exec. and archives successfully $Rdeleted ❌$W--------\n"
	@echo "$W>>>>>>>>>>>>>>>>>>>>> $ZCleaning is $Gdone ✅ $W<<<<<<<<<<<<<<<<<<<<<\n\n"

# Removes objects and executables and remake
re: fclean
	@$(MAKE) all

# Displays tools available
help:
	@echo "$$HELP"

# For testing purposes
test:
	@echo "\n\n$W>>>>>>>>>>>>>>>>>>>>>>>>>>> $YTESTING $W<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n"
	@echo "$W---------------------- $Z./push_swap 3 1 2 $W-----------------------"
	@./$(NAME) $(TEST1_ARGS)
	@echo "$W---------------------- $Z./push_swap 4 7 2 $W-----------------------"
	@./$(NAME) $(TEST2_ARGS)
	@echo "$W-------------------- $Z./push_swap -18 47 65 $W---------------------"
	@./$(NAME) $(TEST3_ARGS)
	@echo "$W---------------------- $Z./push_swap 5 2 -3 $W----------------------"
	@./$(NAME) $(TEST4_ARGS)
	@echo "$W>>>>>>>>>>>>>>>>>>>>>>>>> $YEND TESTS ✅ $W<<<<<<<<<<<<<<<<<<<<<<<<<\n"

norm :
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>>>> $YNORMINETTE $W<<<<<<<<<<<<<<<<<<<<<<<<<<$Z\n"
	@norminette $(SRCS) $(HEADER) $(LIBFT_DIR) $(PRINTF_DIR)
	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>> $YNORMINETTE ✅ $W<<<<<<<<<<<<<<<<<<<<<<<<<<"

#lsan : $(LSAN)
#lsan : CFLAGS += -Wno-gnu-include-next -ILeakSanitizer -LLeakSanitizer -llsan -lc++
#$(LSAN) :
#	@if [ ! -d "LeakSanitizer"]; then git clone https://github.com/mhahnFr/LeakSanitizer.git; fi
#	@$(MAKE) -C LeakSanitizer

# Verifications before sumission
#checkup: 
#	@$(MAKE) test
#	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>>>>> $YMEMORY $W<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
#	$(MAKE) lsan
#	@echo "\n$W>>>>>>>>>>>>>>>>>>>>>>>>>> $YMEMORY ✅ $W<<<<<<<<<<<<<<<<<<<<<<<<<<<"
#	@$(MAKE) norm

# Opens the subject
pdf:
	@open https://cdn.intra.42.fr/pdf/pdf/66937/fr.subject.pdf

map:
	@open https://whimsical.com/push-swap-X6SXns36GzkpCxF5zxkMFJ

text:
	@open https://www.dummytextgenerator.com/#jump

mem:
	@echo "\n\n$W>>>>>>>>>>>>>>>>>>>>>>>>>>> $YMEMORY $W<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n"
	@echo "$W---------------------- $Z./push_swap 3 1 2 $W-----------------------"
	@leaks -atExit -- ./$(NAME) $(TEST1_ARGS)
	@echo "$W---------------------- $Z./push_swap 3 1 2 $W-----------------------"
	@valgrind --leak-check=full ./$(NAME) $(TEST1_ARGS)
	@echo "$W---------------------- $Z./push_swap 3 3 2 $W-----------------------"
	@leaks -atExit -- ./$(NAME) $(TEST5_ARGS)
	@echo "$W---------------------- $Z./push_swap 3 3 2 $W-----------------------"
	@valgrind --leak-check=full ./$(NAME) $(TEST5_ARGS)
	@echo "$W---------------------- $Z./push_swap 3 A 2 $W-----------------------"
	@leaks -atExit -- ./$(NAME) $(TEST6_ARGS)
	@echo "$W---------------------- $Z./push_swap 3 A 2 $W-----------------------"
	@valgrind --leak-check=full ./$(NAME) $(TEST6_ARGS)
	@echo "$W>>>>>>>>>>>>>>>>>>>>>>>>> $YEND TESTS ✅ $W<<<<<<<<<<<<<<<<<<<<<<<<<\n"

	valgrind --leak-check=full ./programme

# Avoids file-target name conflicts
.PHONY: all dir clean fclean re test norm lsan pdf help mem map text