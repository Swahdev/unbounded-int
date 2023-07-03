EXEC = testeur

SRC = unbounded_int.c

OBJ = ${addprefix objects/, $(SRC:.c=.o)}

CC = gcc

CFLAGS = -Wall -g -pedantic

objects/%.o: %.c
	@mkdir -p ${dir $@}
	$(CC) $(CFLAGS) -c $< -o $@

NAME :	$(OBJ)
		$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

all :  $(NAME)

clean : 
		rm -f $(OBJ)

fclean : 	clean
			rm -f $(EXEC)

re : fclean all

.PHONY : all clean fclean re