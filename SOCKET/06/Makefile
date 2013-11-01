server:server_select.c str_echo.c
	gcc server_select.c signal.c str_echo.c -o server
server1:server_select1.c str_echo.c
	gcc server_select1.c signal.c str_echo.c -o server1
server_poll:server_poll.c str_echo.c
	gcc server_poll.c signal.c str_echo.c -o server_poll

client:client_select.c str_select.c
	gcc client_select.c str_select.c -o client
client1:client_select.c str_select1.c
	gcc client_select.c str_select1.c -o client1

.PHONY:clean
clean:
	rm server server1 client client1 server_poll
