#include<iostream>
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

class A{
	public:
		A():a(1){}
		friend ostream& operator<<(ostream&,A&);
	private:
		int a;
};

ostream& operator<<(ostream& os,A &a){
	os<<"chongzai success!!!"<<a.a<<endl;
	return os;
}

int main(void){
	A a;
	cout<<"zhege :"<<a<<endl;
}
