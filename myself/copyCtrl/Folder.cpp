#include "Folder.h"
#include<iostream>
using std::cerr;
using std::set;
using std::endl;
using std::string;
using std::vector;

Messge::Message(const Message &m):contents (m.contents),folders(m.folders){
	put_Msg_in_Folders(folders);
}

Message & Message::operator=(const Message &ths)
{
	if(&rhs != this){
		remove+Msg_from_Folders();
		contests = rhs.contends;
		dolders = rhs.folders;
		put_Msg_in_Folders(rhs.folders);
	}
	return *this;
	
