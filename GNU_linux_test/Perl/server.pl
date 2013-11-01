#!/usr/bin/perl -w
use Socket;

$socketname="/tmp/request";
unlink($socketname);

$addr = sockaddr_un($socketname);
socket(REQSOCK,PF_UNIX,SOCK_STREAM,0) || die "No socket:$!";
bind(REQSOCK,$addr)	|| die "Can't bind:$!";
listen(REQSOCK,5)	|| die "Can't listen:$!";

for($waiting = 0;
		accept(REQUEST,REQSOCK) || $waiting;
		$waiting = 0,close REQUEST){
	next if $waiting;
	print REQUEST "Hi, there client.\nBye for now\n";
}
