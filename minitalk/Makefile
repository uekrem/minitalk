NAME = serverclient.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

printf = ./src/libftprintf.a

CLIENT = client

SERVER = server

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): server.o
	make -C ./src
	$(CC) $(CFLAGS) $< $(printf) -o $@
	
$(CLIENT): client.o
	make -C ./src
	$(CC) $(CFLAGS) $< $(printf) -o $@
	
clean:
	make fclean -C ./src
	rm server client server.o client.o
	
fclean: clean
	
re: fclean all
	
.PHONY: all clean fclean re
