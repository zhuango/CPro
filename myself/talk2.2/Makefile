server: tcp_server.c readline.c
	gcc -pthread tcp_server.o readline.c -o server

client: tcp_client.o
	gcc -pthread tcp_client.o -o client
tcp_client.o: tcp_client.c
	gcc -pthread -c tcp_client.c -o tcp_client.o

.PHONY:clean
clean:
	rm *.o server client
