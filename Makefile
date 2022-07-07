NAME = push_swap

BONUS = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC  = 	commands_more.c helper.c list.c	parse.c    score_two.c \
		sort_arr.c   	sort_three.c 	commands.c find_best.c \
		manage_elem.c   push_swap.c     score.c    sort.c  sort_five.c

SRC_BONUS = checker.c parse_bonus.c sort_arr_bonus.c helper_bonus.c  list_bonus.c  gnl.c \
			commands_more_bonus.c commands_bonus.c stack_sorted.c read_commands.c\
			clean_commands.c

OBJ = ${SRC:%.c=%.o}

OBJ_BONUS = ${SRC_BONUS:%.c=%.o}

HEADER = push_swap.h

HEADER_BONUS = checker.h

DIR_LIB = libft

LIB = $(DIR_LIB)/libft.a

all : $(NAME)

bonus :$(BONUS)

lib : 
	make -sC $(DIR_LIB)

$(NAME) : lib $(OBJ) $(LIB) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

$(BONUS) : lib $(OBJ_BONUS) $(LIB) $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIB) -o $(BONUS)

%.o : %.c $(HEADER)
	gcc $(CFLAGS) -c $< -o $@ -g

clean :
	rm -f $(OBJ) $(OBJ_BONUS)
	make clean -C $(DIR_LIB)

fclean : clean
	rm -f $(NAME) $(BONUS)
	make fclean -C $(DIR_LIB)
	
re : fclean all bonus

.PHONY : all clean fclean re