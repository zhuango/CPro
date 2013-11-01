#include "Folder.h"
#include<iostream>
using std::cerr;
using std::endl;
using std::set;
using std::string;
using std::vector;

Message::Message(const Message &m):
	contents(m.contents),folders(m.folders)
{
	put_Msg_in_Folders(folders);
}

Message& Message::operator=(const Message &rhs){
	if(&rhs != this) {
		remove_Msg_from_Folders();
		contents = rhs.contents;
		folders = rhs.folders;
		put_Msg_in_Folders(rhs.folders);
	}
	return *this;
}

Message::~Message(){
	remove_Msg_from_Folders();
}

void Message::put_Msg_in_Folders(const set<Folder*> &rhs){
	for(std::set<Folder*>::const_iterator beg = rhs.begin();
			beg != rhs.end();beg++){
		(*beg)->addMsg(this);
	}
}

void Message::remove_Msg_from_Folders(){

	for(std::set<Folder*>::const_iterator beg = folders.begin();
			beg != folders.end(); ++beg){
		(*beg)->remMsg(this);
	}
}

void Folder::copy_msgs(const set<Message*> &m){

	for(Msg_iter beg = m.begin();beg != m.end();++beg){
		(*beg)->save(*this);
	}
}

Folder::Folder(const Folder &f){
	copy_msgs(f.msgs);
}

Folder& Folder::operator=(const Folder &f){

	if(&f != this){
		empty_msgs();
		copy_msgs(f.msgs);
	}

	return *this;
}

Folder::~Folder(){
	empty_msgs();
}

void Folder::empty_msgs(){
	Msg_iter it = msgs.begin();
	while(it != msgs.end()){
		Msg_iter next = it;
		++next;
		(*it)->remove(*this);
		it = next;
	}
}

void Message::save(Folder &f){
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f){
	folders.erase(&f);
	f.remMsg(this);
}

void Folder::save(Message &m){
	msgs.insert(&m);
	m.addFldr(this);
}

void Folder::remove(Message &m){
	msgs.erase(&m);
	m.remFldr(this);
}
vector<Folder*> Message::get_folders(){
	return vector<Folder*>(folders.begin(),folders.end());
}

vector<Message*> Folder::message(){
	return vector<Message*>(msgs.begin(),msgs.end());
}

void Folder::debug_print(){
	cerr << "Folder contiain " << msgs.size() << "message" << endl;
	int ctr = 1;
	for(Msg_iter beg = msgs.begin();beg != msgs.end();++beg)
		cerr << "Message " << ctr++ << ":\n\t"
		     << (*beg)->print_message() << endl;
}

void Message::debug_print(){
	cerr << "Message:\n\t" << contents << endl;
	cerr << "Appears in " << folders.size() << " Folders" <<endl;
}

