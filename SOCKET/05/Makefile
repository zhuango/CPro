echo_server:echo_server.c str_echo.c
	gcc echo_server.c str_echo.c -o echo_server

server_add:echo_server.c str_add.c
	gcc echo_server.c str_add.c -o server_add
echo_client:echo_client.c str_cli.c
	gcc echo_client.c str_cli.c -o echo_client
server1:server1.c str_echo.c signal.c
	gcc server1.c str_echo.c signal.c -o server1

client1:client1.c str_cli.c
	gcc client1.c str_cli.c -o client1
client_pipe:client_sigpipe.c signal.c str_lic_noDeal.c
	gcc client_sigpipe.c signal.c str_lic_noDeal.c -o client_pipe

.PHONY:clean
clean:
	rm echo_server echo_client client_pipe server1 client1

