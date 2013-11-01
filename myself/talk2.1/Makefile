server: tcp_server.o
	gcc -pthread tcp_server.o -o server
tcp_server.o:tcp_server.c
	gcc -pthread -c tcp_server.c -o tcp_server.o

client: tcp_client.o
	gcc -pthread tcp_client.o -o client
tcp_client.o: tcp_client.c
	gcc -pthread -c tcp_client.c -o tcp_client.o

.PHONY:clean
clean:
	rm *.o server client
