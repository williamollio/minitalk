CC = GCC

CFLAGS = -Wall -Wextra -Werror

INCLUDES = minitalk.h

SERVER = server

CLIENT = client

SERVER_SRC = server.c

CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

LIBFT_PATH = ./libft/

$(NAME) : $(SERVER) $(CLIENT)

all: subsystem $(NAME)

subsystem :
	make -C ./libft
	cp ./libft/libft.a libft.a

server: subsystem $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) libft.a -o server

client: subsystem $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) libft.a -o client

bonus: all

clean:
	rm -f $(SERVER_OBJ)
	rm -f $(CLIENT_OBJ)
	rm -f $(LIBFT_PATH)*.o

fclean: clean
	rm -f $(LIBFT_PATH)libft.a
	rm -f libft.a
	rm -f $(SERVER)
	rm -f $(CLIENT)

re: fclean all
