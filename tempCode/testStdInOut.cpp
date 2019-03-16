#include "MyRandom.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int caseCout;
    cin >> caseCout;
    random rdNum;
    while (caseCout--)
    {
        int i = rdNum.GetRand(1, 100);
        int j = rdNum.GetRand(1, 100);

        cout << i << "x" << j << "=" << i * j << "\n";
    }
    //cout << rdNum.GetRand(1, 100) / rdNum.GetRand(0, 0) << "\n";
    return 0;
}
