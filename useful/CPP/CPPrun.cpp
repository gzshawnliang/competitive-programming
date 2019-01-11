#include <fstream>
#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("CPPrun.in");
ofstream fout("CPPrun.out");
int main()
{
    int n;
    cin >> n;
    fout << n / 2 << '\n';

    return 0;
}
