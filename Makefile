NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = main.c push_swap.c split.c operations1.c operations2.c \
operations3.c check_argv.c functions_stack.c help_push_swap.c \
get_highest.c

BONUS_SRC = bonus/checker.c bonus/main_help.c bonus/get_next_line.c bonus/get_next_line_utils.c \
            src/check_argv.c src/functions_stack.c src/get_highest.c \
            src/help_push_swap.c src/operations1.c src/operations2.c \
            src/operations3.c src/push_swap.c src/split.c
OBJ_DIR = obj

SRCS = $(addprefix src/, $(SRC))
OBJS = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRCS))

inclfolder = include
INCLUDES = -I $(inclfolder)

Color_Off = '\033[0m'
Red = '\033[0;91m'
Green = '\033[0;92m'
Yellow = '\033[0;93m'
Cyan = '\033[0;96m'

MSG1 = @echo $(Green)"$(NAME) compiled successfully"$(Color_Off)
MSG2 = @echo $(Cyan)"cleaned completely"$(Color_Off)
MSG3 = @echo $(Yellow)"$(NAME) cleaned"$(Color_Off)
MSG4 = @echo $(Red)"$(BONUS_NAME) compiled successfully"$(Color_Off)

all: $(NAME)

bonus: 
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(BONUS_NAME) $(BONUS_SRC)
	$(MSG4)

$(NAME): $(OBJS)
		@ $(CC) $(CFLAGS) $(INCLUDES) $(SRCS) -o $(NAME)
		$(MSG1)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
		@rm -rf $(OBJ_DIR)
		$(MSG2)

fclean: clean
		@rm -rf $(NAME) $(BONUS_NAME) $(OBJ_DIR)
		$(MSG3)

re: fclean all

.PHONY: all clean fclean re bonus