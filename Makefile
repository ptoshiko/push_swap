NAME = push_swap
CC = gcc
CFLAGS = 
SRC  = 	commands_more.c  helper.c        list.c          parse.c    score_two.c     sort_arr.c      sort_three.c commands.c      find_best.c manage_elem.c   push_swap.c     score.c         sort.c          sort_five.c

OBJ = $(patsubst %.c,%.o,$(SRC))
INCLUDES = push_swap.h
DIR_LIB = libft
LIB = $(DIR_LIB)/libft.a

all : $(NAME)

lib : 
	make -sC $(DIR_LIB)

$(NAME) : lib $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) 

%.o : %.c $(INCLUDES)
	gcc $(CFLAGS) -c $< -o $@ -g

clean :
	rm -f $(OBJ)
	make clean -C $(DIR_LIB)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(DIR_LIB)
	
re : fclean all

.PHONY : all clean fclean re