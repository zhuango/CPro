mainserver:mainserver.c fop.c
	gcc mainserver.c fop.c -o mainserver
client:client.c fop.c
	gcc client.c fop.c -o client
	
all:mainserver client

.PHONY:clean
clean:
	rm mainserver client
