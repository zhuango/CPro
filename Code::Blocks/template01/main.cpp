#include <iostream>

using namespace std;

template<typename T>
void print_(T Type)
{
    cout << Type << endl;
}

int main()
{
    print_(10);
    print_(10000.02004);
    print_("nima");
    return 0;
}
