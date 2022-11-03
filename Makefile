LIBFT = ./Libft/libft.a

NAME_S = serveur

NAME_C = client

HEADER_S = serveur.h

HEADER_C = client.h

CC =  gcc

CFLAGS = -Wall #-Wextra -Werror

SRC_SERVEUR = serveur.c

SRC_CLIENT = client.c

OBJ_SERVEUR = $(SRC_SERVEUR:.c=.o)

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all : $(NAME_S) $(NAME_C)

$(NAME_S) : $(LIBFT) $(OBJ_SERVEUR)
	$(CC) -o $(NAME_S) $(CFLAGS) $(OBJ_SERVEUR) -L./Libft -lft

$(NAME_C) : $(LIBFT) $(OBJ_CLIENT)
	$(CC) -o $(NAME_C) $(CFLAGS) $(OBJ_CLIENT) -L./Libft -lft

$(LIBFT) :
	make -C Libft

%.o:%.c $(HEADER_S) $(HEADER_C)
	$(CC) $(CFLAGS) -o $@ -c $< -I . -I Libft

clean : 
	rm -f $(OBJ_SERVEUR) $(OBJ_CLIENT)
	make clean -C Libft

fclean : clean
	rm -f $(NAME_S) $(NAME_C)
	make fclean -C Libft

re : fclean all

.PHONY : all clean fclean re
