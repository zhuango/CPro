all: client server

client: tcp_client.c
	gcc -pthread tcp_client.c -o client
server: tcp_server.c
	gcc -pthread tcp_server.c -o server

.PHONY: clean
clean:
	rm client server
