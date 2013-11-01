#!/usr/bin/perl -w

use Socket;
socket(REQSOCK,PF_UNIX,SOCK_STREAM,0) || die "No socket: $!";
connect(REQSOCK,sockaddr_un("/tmp/request")) || die "Can't connect: $!";

while(<REQSOCK>){
	print;
}
