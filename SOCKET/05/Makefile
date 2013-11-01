echo_server:echo_server.c str_echo.c
	gcc echo_server.c str_echo.c -o echo_server

server_add:echo_server.c str_add.c
	gcc echo_server.c str_add.c -o server_add
echo_client:echo_client.c str_cli.c
	gcc echo_client.c str_cli.c -o echo_client
server1:server1.c str_echo.c signal.c
<<<<<<< HEAD
	gcc server1.c str_echo.c signal.c -o server

client1:client1.c str_cli.c
	gcc client1.c str_cli.c -o client
=======
	gcc server1.c str_echo.c signal.c -o server1

client1:client1.c str_cli.c
	gcc client1.c str_cli.c -o client1
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
client_pipe:client_sigpipe.c signal.c str_lic_noDeal.c
	gcc client_sigpipe.c signal.c str_lic_noDeal.c -o client_pipe

.PHONY:clean
clean:
<<<<<<< HEAD
	rm echo_server echo_client client_pipe
=======
	rm echo_server echo_client client_pipe server1 client1
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4

