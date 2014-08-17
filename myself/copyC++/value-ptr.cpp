#include<iostream>
using std::ostream;
using std::cout;
using std::endl;
#include<string>

class HasPtr{
	public:
		HasPtr(const int &p,int i): ptr(new int(p)),val(i) {}

		HasPtr(const HasPtr &orig):
			ptr(new int (*orig.ptr)),val(orig.val) {}

		HasPtr& operator=(const HasPtr&);

		~HasPtr() {delete ptr;}

		friend ostream& operator<<(ostream&,const HasPtr&);

		int get_ptr_val() const {return *ptr;}
		int get_int() const {return val;}

		void set_ptr(int *p) { ptr = p;}
		void set_int(int i)  { val = i;}


		int  *get_ptr()const {return ptr;}
		void set_ptr_val(int p) const { *ptr = p;}

	private:
		int *ptr;
		int val;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs){
	*ptr = *rhs.ptr;
	val = rhs.val;

	return *this;
}
ostream& operator<<(ostream &os,const HasPtr &hp){

	os << "*ptr: " << hp.get_ptr_val() << "\tval: " << hp.get_int() << endl;
	return os;
}

int main(){

	int obj = 0;

	HasPtr ptr1(obj,42);
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
	HasPtr ptr(*ip,10);
	delete ip;
	ptr.set_ptr_val(0);

	cout << "(4) ptr: " << ptr << endl;

	return 0;
}
