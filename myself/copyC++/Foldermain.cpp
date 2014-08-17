#include "Folder.h"
#include<string>
using std::string;

int main(){
	string s1("contents1");
	string s2("contents2");
	string s3("contents3");
	string s4("contents4");
	string s5("contents5");
	string s6("contents6");

	Message m1(s1);
	Message m2(s1);
	Message m3(s1);
	Message m4(s1);
	Message m5(s1);
	Message m6(s1);

	Folder f1;
	Folder f2;

	m1.save(f1);
	m3.save(f1);
	m5.save(f1);
	m1.save(f2);
	m2.save(f2);
	m4.save(f2);
	m6.save(f2);

	m1.debug_print();
	m2.debug_print();

	Message c1(m1);
	Message c2(m2) ,c4(m4),c6(m6);

	m1.debug_print();
	f2.debug_print();

	return 0;
}
