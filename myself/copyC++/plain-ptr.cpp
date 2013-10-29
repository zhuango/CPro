#include<iostream>
using std::ostream;
using std::cout;
using std::endl;
#include<string>

class HasPtr{
	public:
		friend ostream& operator<<(ostream&,const HasPtr&);

		HasPtr(int *p,int i): ptr(p) ,val(i) {}

		int *get_ptr() const {return ptr;}
		int get_int() const {return val;}

		void set_ptr(int *p) {ptr = p;}
		void set_int(int i)  { val = i;}

		int  get_ptr_val() const {return *ptr;}
		void set_ptr_val(int val) const { *ptr = val;}

	private:
		int *ptr;
		int val;
};

void show_copy_control(){

	int i = 42;
	HasPtr p1(&i,42);
	HasPtr p2 = p1;

	cout << p2.get_ptr_val() << endl;

	p1.set_ptr_val(0);

	cout << p2.get_ptr_val() << endl;
}

int main(void){
	show_copy_control();

	int obj = 0;

	HasPtr ptr1(&obj,42);
	HasPtr ptr2(ptr1);

	cout << "(1) ptr1: " << ptr1 << endl << "ptr2: " << ptr2 << endl;

	ptr1.set_ptr_val(42);
	ptr2.get_ptr_val();

	cout << "(2) ptr1: " << ptr1 << endl << "ptr2: " << ptr2 << endl;

	ptr1.set_int(0);
	ptr2.get_int();
	ptr1.get_int();

	cout << "(3) ptr1: " << ptr1 << endl << "ptr2: " << ptr2 << endl;

	int *ip = new int(42);

	HasPtr ptr(ip,10);
	delete ip;
	ptr.set_ptr_val(0);

	cout << "(4) ptr: " << ptr << endl;

	return 0;
}

ostream& operator<<(ostream &os,const HasPtr &hp){

	cout << "*ptr: " <<hp.get_ptr_val() << "\tval: " << hp.get_int() << endl;
	return os;
}
