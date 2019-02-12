#include <bits/stdc++.h>

using namespace std;

//ifstream fin("temp.in");
//ofstream fout("temp.out");

int main()
{
    int a =0 | 1;
    cout << a << "\n";

    a=  1 | 1;
    cout << a << "\n";

    a = 1 | 0;
    cout << a << "\n";

    a = 0 | 0;
    cout << a << "\n";

    a = 0 ;
    a |= 1 & 1 ;     //a = a | (1 & 1);
    cout << a << "\n";
    return 0;
}
