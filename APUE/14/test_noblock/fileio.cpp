#include<iostream>
#include<fstream>
#include<string>

int main(void)
{
	using namespace std;
	string filename="cpp.file";

	ofstream fout(filename.c_str());

	for(int i =0; i < 1000000; i++){
		fout << "fddddsddfss\n";
	}
	fout.close();
}
