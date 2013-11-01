msg_server: msg_server.c server.c msg_sr.c
	gcc msg_server.c server.c msg_sr.c msg.c -o msg_server
msg_client: msg_client.c client.c msg_sr.c
	gcc msg_client.c client.c msg_sr.c msg.c -o msg_client
all:msg_server msg_client

<<<<<<< HEAD
.PHONY:clean
clean: 
=======
.PHONY:cleans
clean:rm 
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
	rm msg_server msg_client
