/*
ID: og192li1
PROG: gift1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>


using namespace std;

int main()
{
	int NP;
	std::string str;
	int sum, per;

	ofstream fout("gift1.out");
	ifstream fin("gift1.in");

	fin >> NP;
	map<std::string, int> p;
	vector<std::string> vstr;
	for(int i = 0; i < NP; i++){
		fin >> str;
		vstr.push_back(str);
		p.insert(map<std::string, int>::value_type(str, 0));
	}

	for(int j = 0; j < NP; j++){
		fin >> str;
		fin >> sum;
		fin >> per;
		p[str] -= sum;
		if(per != 0)
			p[str] += sum % per;
		else
			p[str] += sum;

		for(int i = 0; i < per; i++) {
			fin >> str;
			p[str] += sum / per;
		}
	}

	for(int i = 0; i < NP; i++) {
		fout << vstr[i] << " " << p[vstr[i]]<< endl;
	}
	return 0;
}
