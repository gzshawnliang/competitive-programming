#include "MyRandom.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int caseCout;
    cin >> caseCout;
    random rdNum;
    int k = 1;
    while (caseCout--)
    {
        int i = rdNum.GetRand(1, 100);
        int j = rdNum.GetRand(1, 100);

        cout << k << ") " << i << "x" << j << "=" << i * j << "\n";
        ++k;
    }
    //cout << rdNum.GetRand(1, 100) / rdNum.GetRand(0, 0) << "\n";
    return 0;
}
