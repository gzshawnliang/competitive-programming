#include <bits/stdc++.h>

using namespace std;

void printBitSet()
{
    
}

int main()
{
    bitset<10> b1;
    vector<bitset<10>> b2(8);
    b1[2]=1;
    cout << b1[1] << " " << b1[2] << "\n";

    b2[1][2]=1;
    cout << b2[1][0] << " " <<b2[1][2] << "\n";
 
    vector<bitset<10>> b3(8,bitset<10>().set());
    bitset<100> bs  = bitset<100>().set();
    cout << "\n";
    for (int i = 0; i <= bs.count() - 1; ++i)
    {
        cout << bs[i] << " ";
    }
    return 0;
}