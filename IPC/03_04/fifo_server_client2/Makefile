<<<<<<< HEAD
client: mainclient.c client.c 
	gcc mainclient.c client.c  -o client

server: mainserver.c server.c 
	gcc mainserver.c server.c -o server

.PHONY:clean
clean:	
	rm  client server
=======
mainserver: mainserver.c fop.c server.c
	gcc mainserver.c fop.c server.c -o mainserver
mainclient: mainclient.c fop.c client.c
	gcc mainclient.c fop.c client.c -o mainclient

all:mainclient mainserver
.PHONY:clean
clean:
	rm mainserver mainclient
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
