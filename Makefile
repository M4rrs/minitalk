SERVER = server
CLIENT = client
INCLUDE = minitalk.h
CC = gcc
CCFLAGS = -Wall -Werror -Wextra
LIB = libft

all: server client

server: lib
	${CC} ${CCFLAGS} -o ${SERVER} -I ${INCLUDE} server.c -Llibft -lft 

client: lib
	${CC} ${CCFLAGS} -o ${CLIENT} -I ${INCLUDE} client.c -Llibft -lft 
	
lib:
	make re -C ${LIB}

fclean: clean
	rm -rf ${SERVER} ${CLIENT}
	make fclean -C ${LIB}

clean:
	rm -rf *.o

re:	fclean all