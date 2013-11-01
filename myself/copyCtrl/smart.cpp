#include<iostream>
using std::ostream;
using std::cout;
using std::endl;
#include<string>
#include<cstddef>
using std::size_t;

class U_Ptr {
	friend class HasPtr;
	int *ip;
	size_t use;
	U_Ptr(int *p): ip(p) ,use(1){}
	~U_Ptr() {delete ip;}
};

class HasPtr{
	public:
		HasPtr(int *p,int i): ptr( new U_Ptr(p) ),val(i){}

		HasPtr(const HasPtr &orig):
			ptr(orig.ptr),val(orig.val) {++(ptr->use);}

		HasPtr& operator=(const HasPtr&);

		~HasPtr() { if (--ptr->use == 0) delete ptr;}

		friend ostream& operator<<(ostream&, const HasPtr&);

		int *get_ptr() const {return ptr->ip;}
		int get_int() const {return val;}
		void set_ptr(int *p) {ptr->ip = p;}
		void set_int(int i) {val = i;}

		int get_ptr_val() const {return *ptr->ip;}
		int set_ptr_val(int i) { *ptr->ip = i;}

	private:
		U_Ptr *ptr;
		int val;
};

HasPtr& HasPtr::operator = (const HasPtr &rhs)
{
	++rhs.ptr->use;
	if(--ptr->use == 0)
		delete ptr;

	ptr = rhs.ptr;
	val = rhs.val;
	return *this;
}

ostream& operator<<(ostream &os,const HasPtr &hp)
{
	os<<"*ptr: "<<hp.get_ptr_val()<<"\tval: "<<hp.get_int()<<endl;
	return os;
}

int main(void)
{
	int obj = 0;
	HasPtr ptr1(&obj,42);
	HasPtr ptr2(ptr1);

	cout<<"(1) ptr1: "<<ptr1<<endl<<"ptr2: "<<ptr2<<endl;

	ptr1.set_ptr_val(42);
	ptr2.get_ptr_val();

	cout<<"(2) ptr1: "<<ptr1<<endl<<"ptr2: "<<ptr2<<endl;

	ptr1.set_int(0);
	ptr2.get_int();
	ptr1.get_int();

	cout<< "(3) ptr1: "<<ptr1<<endl<<"ptr2: "<<ptr2<<endl;


	return 0;
}
