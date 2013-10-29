msg_server: msg_server.c server.c msg_sr.c
	gcc msg_server.c server.c msg_sr.c msg.c -o msg_server
msg_client: msg_client.c client.c msg_sr.c
	gcc msg_client.c client.c msg_sr.c msg.c -o msg_client
all:msg_server msg_client

.PHONY:cleans
clean:
	rm msg_server msg_client
