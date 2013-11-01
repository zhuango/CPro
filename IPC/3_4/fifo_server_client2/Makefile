mainserver: mainserver.c fop.c server.c
	gcc mainserver.c fop.c server.c -o mainserver
mainclient: mainclient.c fop.c client.c
	gcc mainclient.c fop.c client.c -o mainclient

all:mainclient mainserver
.PHONY:clean
clean:
	rm mainserver mainclient
