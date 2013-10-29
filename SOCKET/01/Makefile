daytimetcp: daytimetcp.o
	gcc daytimetcp.o -o daytimetcp
daytimetcp.o: daytimetcp.c
	gcc -c daytimetcp.c -o daytimetcp.o

daytimetcpsrv:daytimetcpsrv.o
	gcc daytimetcpsrv.o -o daytimetcpsrv
daytimetcpsrv.o:daytimetcpsrv.c
	gcc -c daytimetcpsrv.c -o daytimetcpsrv.o

tcp_server_client:tcp_server_client.o
	gcc tcp_server_client.o -o tcp_server_client
tcp_server_lcient.o:tcp_server_client
	gcc -c tcp_server_client.c -o tcp_server_client.o

tcp_str_client:tcp_str_client.o
	gcc tcp_str_client.o -o tcp_str_clinet
tcp_str_clinet.o:tcp_str_client.c
	gcc -c tcp_str_client.c -o tcp_str_client.o

.PHONY:clean
clean:
	rm daytimetcp daytimetcpsrv tcp_server_client tcp_str_client *.o
