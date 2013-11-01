#!/bin/sh
#test2.sh: a real program with variables, input,
#	and contral flow

BOOK= $NOME/phonebook.data
echo find what name in phonebook
read NAME
if grep $NAME $BOOK  >  /tmp/pb.tmp
then
	echo Enteries for $NAME
	cat /tmp/pb.tmp
else
	echo No enteries for $NAME
fi

rm /tmp/pb.tmp
